#!/usr/bin/env python3
"""build_levels.py: build a disc's programs from their assembly and check each against the disc.

    python3 tools/build_levels.py [--version us|pal] [--asm] [-P 8] [TARGET ...]   # all 49 targets without names

Targets (tools/levels.py targets()): `main` (the main image the loader unpacks), `frontbin` and
`level_NN` for each of the 47 levels. For each one: with --asm its assembly first
(tools/asm_programs.py), then every section's .s is assembled (ee-as), linked at its address with
build/<version>/<target>/<target>.ld (ee-ld), and the linked sections are put back into the disc's
program format (the records of tools/levels.py) and into the dump's ELF layout. It prints
`MATCH` when both SHA-1s are config/<version>/levels.tsv's (programs.tsv's): the program
as the disc stores it, byte for byte.

When words differ, the first differing word of each section is written to
asm/<version>/<program>/words.txt (the assembler did not give it back: it becomes a .word) and the
target is rebuilt, up to --rounds times; the log says which.

The toolchain is the repository's (toolchain/, docs/build/toolchain.md): SN ProDG's ee-as and ee-ld
(binutils 2.10-ee), Linux builds from toolchain/sn-prodg-24 by default; --bin DIR for others.
C is not built into these programs yet (see docs/build/levels.md): they are the disc's code as
assembly, the base that matched C replaces function by function.
"""
import argparse
import hashlib
import os
import re
import subprocess
import sys
import functools
from concurrent.futures import ProcessPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import levels  # noqa: E402
import asm_programs as progasm  # noqa: E402

BIN = os.path.join(ROOT, "toolchain", "sn-prodg-24", "local", "sce", "ee", "gcc", "bin")
ASFLAGS = ["-EL", "-mips3", "-mcpu=r5900"]
GPR = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
       "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]
REG = re.compile(r"\$(%s)\b" % "|".join(GPR))
INCLUDE = re.compile(r'^\.include "([^"]+)"$', re.M)


def flatten(src, dst):
    """The section's .s with its .include lines expanded and the registers' ABI names as numbers
    (binutils 2.10-ee's assembler knows only $sp, $ra, $gp, $fp and $at by name)."""
    text = open(os.path.join(ROOT, src)).read()
    text = INCLUDE.sub(lambda m: open(os.path.join(ROOT, m.group(1))).read(), text)
    text = REG.sub(lambda m: "$%d" % GPR.index(m.group(1)), text)
    open(os.path.join(ROOT, dst), "w").write(text)


def run(cmd, log):
    log.write("+ %s\n" % " ".join(cmd))
    log.flush()
    return subprocess.run(cmd, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT).returncode == 0


ERROR = re.compile(r"^(\S+?):(\d+): (?:Error|Warning):", re.M)
ADDR = re.compile(r"^/\* ([0-9A-F]{6,8}) [0-9A-F]{8} \*/")


def as_errors(flat, log_text):
    """Addresses of the instructions the assembler refused in FLAT (their address comments)."""
    lines = open(os.path.join(ROOT, flat)).read().split("\n")
    out = set()
    for f, n in ERROR.findall(log_text):
        if os.path.normpath(f) == os.path.normpath(flat):
            m = ADDR.match(lines[int(n) - 1])
            if m:
                out.add(int(m.group(1), 16))
    return out


def build(target, info, a, log):
    """Assemble and link one target. Returns (ok, message, {section: addresses to make .word})."""
    _, path, elf_sha1, prog_sha1, secs = info
    d = os.path.join(progasm.build_root(), target)
    objs = [l.rstrip("\n").split("\t") for l in open(os.path.join(d, "objects.txt"))]
    refused = {}
    for src, obj, sec in objs:
        flat = obj[:-2] + ".s"
        flatten(src, flat)
        cmd = [os.path.join(a.bin, "ee-as")] + ASFLAGS + ["-o", os.path.join(ROOT, obj), flat]
        r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
        log.write("+ %s\n%s%s" % (" ".join(cmd), r.stdout, r.stderr[-20000:]))
        if r.returncode:
            bad = as_errors(flat, r.stderr)
            refused.setdefault(sec, set()).update(bad)
            if not bad:
                return False, "ee-as failed on %s" % src, {}
    if refused:
        return False, "ee-as refused %d instructions" % sum(len(v) for v in refused.values()), refused
    out = os.path.join(d, target + ".elf")
    if not run([os.path.join(a.bin, "ee-ld"), "-T", os.path.join(d, target + ".ld"), "-o", out], log):
        return False, "ee-ld failed", {}
    _, built = levels.read_elf(open(out, "rb").read())
    entry, want = levels.read_elf(open(path, "rb").read())
    built = {want[int(name[4:])][0]: b for name, addr, n, k, b in built if name.startswith("pal.")}
    sections, diffs, where = [], {}, []
    for (name, addr, n, kind, b) in want:
        got = built.get(name, b"")
        if got != b:
            k = next((i for i in range(0, min(len(got), len(b)), 4) if got[i:i + 4] != b[i:i + 4]),
                     min(len(got), len(b)))
            diffs[name] = {addr + k}
            where.append("%s at 0x%X (size 0x%X, disc 0x%X)" % (name, addr + k, len(got), len(b)))
        sections.append((addr, n, kind, got))
    if diffs:
        return False, "differs: " + ", ".join(where), diffs
    raw = levels.records(entry, sections)
    elf = levels.write_elf(entry, sections, [s[0] for s in want])
    h, he = hashlib.sha1(raw).hexdigest(), hashlib.sha1(elf).hexdigest()
    if h != prog_sha1 or he != elf_sha1:
        return False, "the program's SHA-1 is %s, the disc's %s" % (h, prog_sha1), {}
    return True, "MATCH: as the disc stores it sha1 %s; ELF sha1 %s" % (h, he), {}


def one_named(target, table, a):
    return one(target, table[target], a)


def one(target, info, a):
    d = os.path.join(progasm.build_root(), target)
    os.makedirs(d, exist_ok=True)
    program = progasm.program_of(target)
    with open(os.path.join(d, "build.log"), "w") as log:
        for rnd in range(a.rounds + 1):
            if rnd or not os.path.exists(os.path.join(d, "objects.txt")):
                progasm.write_target(target, {})
            ok, msg, fix = build(target, info, a, log)
            log.write("round %d: %s\n" % (rnd, msg))
            if ok or not fix or rnd == a.rounds:
                return target, ok, msg + ("" if ok or not rnd else " (after %d rounds)" % rnd)
            # what the assembler refused or did not give back becomes .word (tools/asm_programs.py)
            for sec, addrs in fix.items():
                prog = "main" if sec == "net.text" else program
                with open(os.path.join(progasm.asm_root(), prog, "words.txt"), "a") as f:
                    f.write("".join("%08X %s\n" % (x, sec) for x in sorted(addrs)))
            log.flush()


def main():
    os.environ["RAC_VERSION"] = levels.cli_version()      # the worker processes' version too
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("targets", nargs="*")
    ap.add_argument("--asm", action="store_true", help="write each target's assembly first")
    ap.add_argument("-P", "--parallel", type=int, default=4)
    ap.add_argument("--rounds", type=int, default=0, help="rebuilds with differing words as .word")
    ap.add_argument("--bin", default=BIN, help="folder with ee-as and ee-ld")
    a = ap.parse_args()
    table = {t[0]: t for t in levels.targets()}
    names = a.targets or list(table)
    if a.asm:
        # each program's assembly once, before the parallel builds (copies share it)
        done = {}
        for t in names:
            progasm.write_target(t, done)
        a.asm = False
    bad = 0
    # the programs first, then the copies that are built from their assembly: a program's
    # rounds rewrite that assembly, which must not happen under a copy's build
    first = [t for t in names if progasm.program_of(t) == t]
    for batch in (first, [t for t in names if t not in first]):
        with ProcessPoolExecutor(a.parallel) as ex:
            for t, ok, msg in ex.map(functools.partial(one_named, table=table, a=a), batch):
                print("%s: %s" % (t, msg), flush=True)
                bad += not ok
    print("%d of %d targets match" % (len(names) - bad, len(names)))
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
