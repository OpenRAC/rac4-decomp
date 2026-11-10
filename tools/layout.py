"""
Where a function lives: its catalogue row, its retail bytes, its assembly,
its source file and its near-miss file (docs/contributing/workflow.md, docs/build/overlays.md).
Shared by tools/try_func.py, tools/wave.py, tools/nonmatching.py and
tools/auto_structs.py, so the layout is written down once.

Standard library only (pyelftools only inside retail_bytes()).
"""
from __future__ import annotations
import os
import re
from functools import lru_cache
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OVERLAY_NAME = re.compile(r"^func_(L\d\d)_([0-9A-F]{8})$")
MAIN_NAME = re.compile(r"^func_([0-9A-F]{8})$")
CORE_END, NET_START = 0x163B80, 0x1E00000
# libgcc and libm are rebuilt from their own sources, never decompiled.
LIBGCC_RANGE = (0x12EE30, 0x131A00)


def _rows(path: Path):
    if path.exists():
        for line in path.read_text().splitlines():
            if line and not line.startswith("#"):
                yield line.split("\t")


@lru_cache(None)
def levels() -> dict[str, tuple[str, str]]:
    """{'L01': (wrench directory, src directory 'l01_dreadzone_station')}."""
    out = {}
    for i, d, _, _ in _rows(ROOT / "config/overlays.tsv"):
        out[i] = (d, "l%s_%s" % (i[1:], d.split("/", 1)[1].split("_", 1)[1]))
    return out


@lru_cache(None)
def libm_addrs() -> frozenset[int]:
    return frozenset(int(r[2], 16) for r in _rows(ROOT / "config/libm.tsv"))


@lru_cache(None)
def catalogue() -> dict[str, dict]:
    """Every function: {name: {addr, size, area, cls, levels}}. area is core,
    net, game, libgcc or libm for the executable, shared or lNN_<level> for
    the overlays; cls is the overlay class (common, level) or ''. Overlay
    functions identical to a resident one (class main) are left out: they
    are matched under their resident name."""
    out = {}
    for name, a, s, seg in _rows(ROOT / "config/functions.tsv"):
        addr = int(a, 16)
        area = ("libgcc" if LIBGCC_RANGE[0] <= addr < LIBGCC_RANGE[1] else
                "libm" if addr in libm_addrs() else
                "core" if seg == "core_text" else "net" if seg == "net_text" else "game")
        out[name] = dict(addr=addr, size=int(s, 16), area=area, cls="", levels=[])
    for name, a, s, cls, lv in _rows(ROOT / "config/overlay_functions.tsv"):
        if cls == "main":
            continue
        area = levels()[lv][1] if cls == "level" else "shared"
        out[name] = dict(addr=int(a, 16), size=int(s, 16), area=area, cls=cls, levels=lv.split(","))
    return out


def info(name: str) -> dict:
    row = catalogue().get(name)
    if row is None:
        raise SystemExit(f"{name}: not in config/functions.tsv or config/overlay_functions.tsv")
    return row


def overlay_root() -> Path:
    return Path(os.environ.get("OVERLAYS") or ROOT / "private/overlays")


def retail_elf(name: str) -> Path:
    """The ELF holding NAME's retail bytes: the executable, or for an overlay
    function the overlay of the level its name gives."""
    m = OVERLAY_NAME.match(name)
    if not m:
        return ROOT / "baserom/SCUS_974.65.elf"
    return overlay_root() / "levels" / levels()[m.group(1)][0] / "overlay.elf"


def retail_bytes(name: str) -> bytes:
    import retail
    from elftools.elf.elffile import ELFFile
    path = retail_elf(name)
    if not path.exists():
        raise SystemExit(f"{path} not found (overlays: set OVERLAYS or link private/overlays)")
    row = info(name)
    with open(path, "rb") as f:
        return retail.read(retail.sections(ELFFile(f)), row["addr"], row["size"])


def asm_path(name: str) -> Path | None:
    m = OVERLAY_NAME.match(name)
    pattern = f"asm/overlays/{m.group(1)}/nonmatchings/*/{name}.s" if m else f"asm/nonmatchings/*/{name}.s"
    return next(iter(sorted(ROOT.glob(pattern))), None)


def src_path(name: str) -> Path:
    """The file a new definition of NAME goes in (docs/contributing/workflow.md, step 1)."""
    row = info(name)
    m = OVERLAY_NAME.match(name)
    if m:
        return ROOT / "src/overlays" / row["area"] / f"{m.group(1)}_{m.group(2)}.c"
    if row["area"] in ("libgcc", "libm"):
        raise SystemExit(f"{name} is {row['area']}: rebuilt from source, not decompiled (docs/build/toolchain.md)")
    return ROOT / "src" / row["area"] / ("%08X.c" % row["addr"])


def nonmatching_path(name: str) -> Path:
    return ROOT / "nonmatching" / info(name)["area"] / f"{name}.c"


DEF = re.compile(r"^(?!extern\b|static\s+inline\b)[A-Za-z_][\w \t\*]*?\b(func_(?:L\d\d_|FB_)?[0-9A-F]{8})\s*\([^;]*$")


def definitions(text: str) -> list[str]:
    """Functions TEXT defines (not just declares)."""
    return [m.group(1) for line in text.splitlines() if (m := DEF.match(line))]


@lru_cache(None)
def defined() -> dict[str, Path]:
    """{function: file} for every C definition in src/."""
    out = {}
    for p in sorted((ROOT / "src").rglob("*.c")):
        for n in definitions(p.read_text(errors="replace")):
            out.setdefault(n, p)
    return out


def definition_span(text: str, name: str) -> tuple[int, int] | None:
    """(first line, last line + 1) of NAME's definition in TEXT, with the
    comment block right above it."""
    lines = text.splitlines()
    for i, line in enumerate(lines):
        m = DEF.match(line)
        if not m or m.group(1) != name:
            continue
        depth, seen = 0, False
        for j in range(i, len(lines)):
            depth += lines[j].count("{") - lines[j].count("}")
            seen = seen or "{" in lines[j]
            if seen and depth == 0:
                break
        start = i
        while start > 0 and lines[start - 1].strip().startswith(("/*", "*", "//")) \
                and not lines[start - 1].strip().startswith("/* cflags:"):
            start -= 1
        return start, j + 1
    return None


def cflags(text: str) -> list[str]:
    """Flags a file adds on its first lines: /* cflags: ... */ (tools/build.sh)."""
    for line in text.splitlines()[:3]:
        m = re.match(r"^/\* cflags: (.*) \*/", line)
        if m:
            return m.group(1).split()
    return []
