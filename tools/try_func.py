#!/usr/bin/env python3
"""
Try C for one function without touching src/: compile it through the real
pipeline (tools/cc.sh, in the container) and compare it with retail the way
tools/audit_matches.py does. Ported from rac1-decomp.

  venv/bin/python tools/try_func.py func_XXXXXXXX candidate.c         # verdict
  venv/bin/python tools/try_func.py func_XXXXXXXX candidate.c --diff  # + differing words
  venv/bin/python tools/try_func.py func_XXXXXXXX c1.c c2.c c3.c      # one verdict each

candidate.c holds the function definition plus the declarations it needs.
If the function is already defined in src/ (a match being cleaned up), the
candidate replaces that definition in a scratch copy of its file, so the
file's other declarations are in scope; otherwise it is compiled on its own,
with `#include "common.h"` added when it has none. `/* cflags: ... */` on the
first lines of the file or the candidate applies, as in tools/build.sh. Work
happens in build/try/<func>/.

Runs on the host: the overlay ELFs it compares against are outside the
repository ($OVERLAYS or private/overlays), so only the compile goes through
tools/docker/run.sh (directly, when wine is on PATH).

The comparison masks only the fields the compiled object relocates
(retail.fields): constants and offsets must equal retail. It is NOT a
link-time check, so a wrong callee or global can still pass. Read the calls
and globals of an EXACT before landing it.

Verdicts: EXACT, BYTES n/size (same size, n bytes differ after masking),
SIZE ours X / retail Y (never keep one), COMPILE (see log.txt).

Every run is logged to build/try/<func>/runs.log. If that folder holds a
BUDGET file (a number, written by tools/wave.py), runs stop once that many
have been logged. --no-budget skips both, for tools that re-check results.
--arm=NAME works in build/try/<func>/NAME/ instead, with its own runs.log
and BUDGET: two agents trying the same function side by side.
"""
from __future__ import annotations
import os
import shutil
import struct
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import layout  # noqa: E402
import retail  # noqa: E402
import elf_layout  # noqa: E402

ROOT = layout.ROOT
TRY = ROOT / "build/try"


def budget_check(work: Path, count: int) -> tuple[int, int | None]:
    """Stops a worker that has used its BUDGET of runs. Returns (runs so far,
    the budget or None)."""
    runs = work / "runs.log"
    used = len(runs.read_text().splitlines()) if runs.exists() else 0
    budget = work / "BUDGET"
    limit = int(budget.read_text().split()[0]) if budget.exists() else None
    if limit is not None and used + count > limit:
        sys.exit(f"BUDGET: {used} of {limit} runs used for {work.name}. "
                 "Write NOTES.md now and stop.")
    return used, limit


def source_text(name: str, candidate: str) -> str:
    """The file to compile: the candidate in place of NAME's definition in its
    src/ file, or the candidate alone."""
    own = layout.defined().get(name)
    if own is not None:
        text = own.read_text(errors="replace")
        span = layout.definition_span(text, name)
        lines = text.splitlines()
        flags = layout.cflags(candidate)
        head = [f"/* cflags: {' '.join(flags)} */"] if flags and not layout.cflags(text) else []
        return "\n".join(head + lines[:span[0]] + [candidate.rstrip("\n")] + lines[span[1]:]) + "\n"
    if '#include "common.h"' not in candidate:
        lines = candidate.splitlines()
        at = 1 if lines and lines[0].startswith("/* cflags:") else 0
        candidate = "\n".join(lines[:at] + ['#include "common.h"', ""] + lines[at:]) + "\n"
    return candidate


def in_container(env: dict[str, str] | None = None) -> bool:
    """True where the compiler runs without starting the container: inside it
    (wine on PATH), or natively on Windows (Git Bash)."""
    environment = os.environ if env is None else env
    return os.name == "nt" or shutil.which("wine", path=environment.get("PATH", os.defpath)) is not None


def compile_all(jobs: list[tuple[Path, Path, list[str]]], work: Path,
                env: dict[str, str] | None = None) -> None:
    """Compiles every (source, object, flags) in one container start."""
    script = work / "compile.sh"
    lines = ["set +e", "export WINEDEBUG=-all"]
    for src, obj, flags in jobs:
        obj.unlink(missing_ok=True)
        log = obj.with_suffix(".log")
        # as_posix: on Windows relative_to() gives backslashes, which bash reads as escapes
        lines.append(f"bash tools/cc.sh {src.relative_to(ROOT).as_posix()} {obj.relative_to(ROOT).as_posix()} "
                     f"{' '.join(flags)} > {log.relative_to(ROOT).as_posix()} 2>&1")
    script.write_text("\n".join(lines) + "\n", newline="\n")
    # Windows otherwise searches system32 before PATH and can launch WSL bash.
    environment = dict(os.environ if env is None else env)
    bash = shutil.which("bash", path=environment.get("PATH", os.defpath))
    if bash is None:
        raise FileNotFoundError("bash not found in compiler environment PATH")
    cmd = [bash, script.relative_to(ROOT).as_posix()]
    if not in_container(environment):
        cmd = [bash, "tools/docker/run.sh", "bash", script.relative_to(ROOT).as_posix()]
    subprocess.run(cmd, cwd=ROOT, env=environment,
                   stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)


def compiled(obj: Path, name: str) -> tuple[bytes, dict, int] | None:
    """The function's code, the object's relocation masks and its offset."""
    from elftools.elf.elffile import ELFFile
    with open(obj, "rb") as f:
        elf = ELFFile(f)
        for function in elf_layout.functions(elf):
            if function.name == name:
                return function.code, retail.reloc_masks(elf, function.section_index), function.start
    return None


def compare(name: str, found: tuple, show: bool) -> str:
    code, masks, start = found
    want = layout.retail_bytes(name)
    # The linker pads functions to 8 bytes with nops (tools/audit_matches.py).
    pad = len(want) - len(code)
    if 0 < pad <= 12 and not any(want[len(code):]):
        want = want[:len(code)]
    if len(code) != len(want):
        verdict = f"SIZE ours {len(code)} / retail {len(want)}"
    else:
        ours, theirs = retail.fields(code, masks, start), retail.fields(want, masks, start)
        diff = sum(((a >> s) & 0xFF) != ((b >> s) & 0xFF)
                   for a, b in zip(ours, theirs) for s in (0, 8, 16, 24))
        verdict = "EXACT" if diff == 0 else f"BYTES {diff}/{len(want)}"
    if show and not verdict.startswith("EXACT"):
        print(diff_lines(code, want, masks, start))
    return verdict


def diff_lines(code: bytes, want: bytes, masks: dict, start: int, limit: int = 60) -> str:
    """The words that differ after masking: offset, ours, retail."""
    import rabbitizer
    dis = lambda w: rabbitizer.Instruction(w, 0, category=rabbitizer.InstrCategory.R5900).disassemble()
    ours, theirs = retail.fields(code, masks, start), retail.fields(want, masks, start)
    out = []
    for i in range(max(len(ours), len(theirs))):
        if i < len(ours) and i < len(theirs) and ours[i] == theirs[i]:
            continue
        a = dis(struct.unpack_from("<I", code, i * 4)[0]) if i < len(ours) else "-"
        b = dis(struct.unpack_from("<I", want, i * 4)[0]) if i < len(theirs) else "-"
        out.append(f"    0x{i * 4:04X}  {a:40} | {b}")
    if len(out) > limit:
        out = out[:limit] + [f"    ... {len(out) - limit} more"]
    return "\n".join(out) if out else "    (no word differs: a size difference at the end)"


def main() -> None:
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    if len(args) < 2:
        sys.exit(__doc__)
    name, cands = args[0], args[1:]
    layout.info(name)
    counted = "--no-budget" not in sys.argv
    show = "--diff" in sys.argv
    arm = next((a.split("=", 1)[1] for a in sys.argv if a.startswith("--arm=")), "")
    work = TRY / name / arm if arm else TRY / name
    work.mkdir(parents=True, exist_ok=True)
    used, limit = budget_check(work, len(cands)) if counted else (0, None)
    out = work / "obj"
    out.mkdir(exist_ok=True)
    jobs = []
    for i, cand in enumerate(cands):
        text = source_text(name, Path(cand).read_text(errors="replace"))
        src = out / f"{i}_{Path(cand).stem}.c"
        src.write_text(text)
        jobs.append((src, src.with_suffix(".o"), layout.cflags(text)))
    compile_all(jobs, work)
    where = layout.defined().get(name)
    where = where.relative_to(ROOT) if where else "standalone"
    failed = False
    for cand, (src, obj, _) in zip(cands, jobs):
        label = f"{Path(cand).name:10s} " if len(cands) > 1 else ""
        found = compiled(obj, name) if obj.exists() else None
        log = obj.with_suffix(".log")
        shutil.copy(log, work / "log.txt") if log.exists() else None
        if found is None:
            verdict = "COMPILE failed" if not obj.exists() else f"COMPILE ({name} not defined)"
        else:
            if show and len(cands) > 1:
                print(f"{label}{name}:")
            verdict = compare(name, found, show)
        if counted:
            used += 1
            with open(work / "runs.log", "a") as runs:
                runs.write(f"{Path(cand).name} {verdict}\n")
        tally = f"   [run {used} of {limit}]" if limit else ""
        print(f"{label}{name}: {verdict}   ({where}){tally}")
        if found is None:
            failed = True
            text = log.read_text(errors="replace") if log.exists() else ""
            errs = [l for l in text.splitlines() if "error" in l.lower() or "undeclared" in l or "parse" in l]
            for l in errs[:8]:
                print("   ", l)
    if failed:
        sys.exit(1)


if __name__ == "__main__":
    main()
