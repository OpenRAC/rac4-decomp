#!/usr/bin/env python3
"""
Try several C variants of the same function against retail in one go.

  venv/bin/python tools/try_variants.py FILE.c  name=func_00497438 ...
FILE.c holds functions with distinct names (v1, v2, ...). Each argument maps a
function name in FILE.c to the retail function it should match. The file is
compiled with the matching compiler (SN GCC 2.95.3 v1.36 -O2 -G8 -fopt-stack) in the
container, then every function is compared with retail like tools/audit_matches.py.
"""
import os
import shutil
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import retail as mp  # noqa: E402
import elf_layout  # noqa: E402
from elftools.elf.elffile import ELFFile  # noqa: E402

ROOT = mp.ROOT


def main() -> int:
    src = Path(sys.argv[1])
    pairs = [a.split("=") for a in sys.argv[2:]]
    out = ROOT / "build" / "try.o"
    cc = "toolchain/sn-prodg-3.01/usr/local/sce/ee/gcc/bin/ee-gcc2953.exe"
    script = ROOT / "build" / "try.sh"
    # Windows (Git Bash) runs the .exe directly; elsewhere it goes through Wine
    script.write_text("export WINEDEBUG=-all\nWINE=$(command -v wine >/dev/null 2>&1 && echo wine || true)\n$WINE %s -O2 -G8 -fopt-stack -mno-check-zero-division %s -Iinclude -c %s -o build/try.o 2>&1 | grep -v warning | grep -v 'In function'\n" % (cc, os.environ.get("EXTRA", ""), Path(src).as_posix()))
    native = os.name == "nt" or shutil.which("wine") is not None
    cmd = ["bash", "build/try.sh"] if native else ["bash", "tools/docker/run.sh", "bash", "build/try.sh"]
    subprocess.run(cmd, cwd=ROOT)
    sizes = {}
    for l in (ROOT / "config" / "functions.tsv").read_text().splitlines()[1:]:
        n, a, s, _ = l.split("\t")
        sizes[n] = (int(a, 16), int(s, 16))
    with open(ROOT / "baserom" / "SCUS_974.65.elf", "rb") as f:
        secs = mp.sections(ELFFile(f))
    with open(out, "rb") as source:
        elf = ELFFile(source)
        syms = {function.name: function for function in elf_layout.functions(elf)}
        for name, target in pairs:
            function = syms.get(name)
            if function is None:
                print(name, "missing")
                continue
            code = function.code
            masks = mp.reloc_masks(elf, function.section_index)
            addr, size = sizes[target]
            retail = mp.read(secs, addr, size)
            pad = size - len(code)
            if 0 < pad <= 12 and not any(retail[len(code):]):
                retail = retail[:len(code)]
            ours, theirs = mp.fields(code, masks, function.start), mp.fields(retail, masks, function.start)
            ok = len(code) == len(retail) and ours == theirs
            eq = sum(1 for a, b in zip(ours, theirs) if a == b)
            print("%-10s -> %s  %s  (%d/%d words)" % (name, target, "EXACT" if ok else "no", eq, len(retail) // 4))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
