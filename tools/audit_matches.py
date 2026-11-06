#!/usr/bin/env python3
"""
Check every compiled function against the retail image.

Reads build/obj/*.o (tools/build.sh) and compares each `func_XXXXXXXX` with
the retail bytes at that address (and each `func_L<level>_<address>` with the bytes
in that level's overlay, found in $OVERLAYS or private/overlays, else in the
level's program dumped from the US disc: tools/levels.py dump). Functions under
US catalogue names the old lists do not have are listed as such and left to
tools/match_map.py, which checks every function at its place on each disc. Only the
fields the compiled object has relocations on are masked (retail.fields: jump
targets, and the immediates of the lui/%lo/$gp accesses to symbols); every
other bit, constants and offsets included, must equal retail. This is NOT a
link-time comparison, so a function that calls or reads the wrong symbol can
still count. Writes build/matches.json.

Usage: venv/bin/python tools/audit_matches.py
"""
import glob
import json
import os
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import retail as mp  # noqa: E402
import elf_layout  # noqa: E402
from elftools.elf.elffile import ELFFile  # noqa: E402

ROOT = mp.ROOT


def main() -> int:
    sizes = {}
    for l in (ROOT / "config" / "functions.tsv").read_text().splitlines():
        if l and not l.startswith("#"):
            n, a, s, _ = l.split("\t")
            sizes[n] = (int(a, 16), int(s, 16))
    with open(ROOT / "baserom" / "SCUS_974.65.elf", "rb") as f:
        secs = mp.sections(ELFFile(f))
    # level overlay functions (func_L<level>_<address>): retail bytes come from the
    # overlay ELFs of an unpacked disc (docs/OVERLAYS.md): $OVERLAYS or private/overlays
    ovl = {}
    for l in (ROOT / "config" / "overlay_functions.tsv").read_text().splitlines():
        if l and not l.startswith("#"):
            n, a, sz, _, _ = l.split("\t")
            ovl[n] = (n.split("_")[1], int(a, 16), int(sz, 16))
    ovl_dirs = {}
    for l in (ROOT / "config" / "overlays.tsv").read_text().splitlines():
        if l and not l.startswith("#"):
            i, d, _, _ = l.split("\t")
            ovl_dirs[i] = d
    ovl_root = Path(os.environ.get("OVERLAYS") or ROOT / "private" / "overlays")
    ovl_secs = {}

    def overlay_secs(i):
        if i not in ovl_secs:
            p = ovl_root / "levels" / ovl_dirs[i] / "overlay.elf"
            if not p.exists():
                # no wrench unpack: the level's program read from the US disc
                # (tools/levels.py dump; its .text is the overlay's, docs/levels.md)
                import levels
                levels.select("us")
                p = Path(levels.elf_path(int(i[1:])))
            ovl_secs[i] = mp.sections(ELFFile(open(p, "rb"))) if p.exists() else None
        return ovl_secs[i]
    # libgcc objects (tools/build_libgcc.sh) are verbatim GCC source: their
    # symbols are paired with retail addresses by config/libgcc.tsv.
    alias = {}
    by_addr = {a: n for n, (a, _) in sizes.items()}
    for tsv in ("libgcc.tsv", "libm.tsv"):
        lg = ROOT / "config" / tsv
        if lg.exists():
            for l in lg.read_text().splitlines():
                if l and not l.startswith("#"):
                    obj, sym, a, _ = l.split("\t")
                    alias[(obj[:-2] if obj.endswith(".o") else obj, sym)] = by_addr[int(a, 16)]
    exact, bad, unlisted = [], [], []
    # src/pal/ holds C written against the PAL disc under PAL names (tools/check_func.py
    # --version pal, tools/match_map.py): not US functions, so not audited here.
    objs = [p for p in glob.glob(str(ROOT / "build" / "obj" / "*.o")) if not Path(p).name.startswith("pal_")]
    for path in sorted(objs + glob.glob(str(ROOT / "build" / "libgcc" / "*.o")) + glob.glob(str(ROOT / "build" / "libm" / "*.o"))):
        with open(path, "rb") as source:
            elf = ELFFile(source)
            for function in elf_layout.functions(elf):
                s = function.symbol
                name = alias.get((Path(path).stem, s.name))
                if name is None:
                    if not re.fullmatch(r"func_(L\d\d_|FB_)?[0-9A-F]{8}", s.name):
                        continue
                    name = s.name
                if name not in ovl and name not in sizes:
                    # a US catalogue name the old lists (config/functions.tsv,
                    # config/overlay_functions.tsv) do not have: tools/match_map.py checks it
                    # against its place on the disc
                    unlisted.append(s.name)
                    continue
                code = function.code
                if name in ovl:
                    lvl, addr, size = ovl[name]
                    osecs = overlay_secs(lvl)
                    if osecs is None:
                        bad.append((s.name, "overlay data not found (set OVERLAYS, or tools/levels.py dump)"))
                        continue
                    retail = mp.read(osecs, addr, size)
                else:
                    addr, size = sizes.get(name, (None, None))
                    if addr is None:
                        bad.append((s.name, "not in config/functions.tsv"))
                        continue
                    retail = mp.read(secs, addr, size)
                # The linker pads functions to 8 bytes with nops: those belong to
                # the retail function but not to the compiled one.
                pad = size - len(code)
                if 0 < pad <= 12 and not any(retail[len(code):]):
                    retail = retail[:len(code)]
                    size = len(code)
                start = function.start
                masks = mp.reloc_masks(elf, function.section_index)
                if len(code) == size and mp.fields(code, masks, start) == mp.fields(retail, masks, start):
                    exact.append(name)
                else:
                    bad.append((s.name, "size %d vs retail %d" % (len(code), size)
                                if len(code) != size else "bytes differ"))
    (ROOT / "build").mkdir(exist_ok=True)
    (ROOT / "build" / "matches.json").write_text(json.dumps({"exact": sorted(exact)}, indent=1))
    print("%d exact, %d not exact" % (len(exact), len(bad)))
    if unlisted:
        print("%d not in the old US lists, not audited here (tools/match_map.py --write checks "
              "them at their catalogue place)" % len(unlisted))
    for n, why in bad:
        print("  %s: %s" % (n, why))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
