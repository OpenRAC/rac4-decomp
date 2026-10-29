#!/usr/bin/env python3
"""
Expand single-precision constants (`li.s`) the way retail's assembler did,
in compiled game code.

GCC writes a float constant as `li.s $fN, value`. Retail's ps2eeas always
builds it in $at: `lui $at, hi` [+ `ori $at, $at, lo`] then `mtc1 $at, $fN`.
The driver's GNU as does that only when the low half of the bits is zero;
otherwise, at -G8, it puts the value in `.lit4` and loads it with
`lwc1 $fN, off($gp)` -- one word instead of three, and a $gp access
retail does not have. In the PAL text the `lui`/`ori`/`mtc1 $at` sequence
appears 13,207 times; no float constant is loaded from `.lit4`.

This rewrites each `li.s` whose low half is non-zero into the explicit
sequence before the first assembly, so tools/ps2eeas_nops.py measures the
real code (its mtc1 rule then sees these mtc1s too). `li.s` with a zero low
half is left to GNU as, which already writes `lui`/`mtc1` (or `mtc1 $0`).
An `li.s` inside a `.set noreorder` block is left alone and reported: three
words cannot fill one delay slot.

usage: python tools/ps2eeas_lis.py IN.s OUT.s
"""
import re
import struct
import sys

LIS = re.compile(r"^(\s*)li\.s\s+(\$f\d+)\s*,\s*([-+0-9.eEinfINFnaN]+)\s*(#.*)?$")


def bits(text: str) -> int:
    return struct.unpack("<I", struct.pack("<f", float(text)))[0]


def main() -> None:
    src, dst = sys.argv[1], sys.argv[2]
    lines = open(src, encoding="utf-8").read().split("\n")
    out = []
    noreorder = False
    expanded = skipped = 0
    for line in lines:
        s = line.strip()
        if s.startswith(".set"):
            if "noreorder" in s:
                noreorder = True
            elif re.search(r"\breorder\b", s):
                noreorder = False
        m = LIS.match(line)
        if m:
            value = bits(m.group(3))
            hi, lo = value >> 16, value & 0xFFFF
            if lo != 0:
                if noreorder:
                    skipped += 1
                else:
                    ind, reg = m.group(1), m.group(2)
                    out += [ind + ".set\tnoat",
                            ind + "lui\t$1,0x%x" % hi,
                            ind + "ori\t$1,$1,0x%x" % lo,
                            ind + "mtc1\t$1,%s" % reg,
                            ind + ".set\tat"]
                    expanded += 1
                    continue
        out.append(line)
    open(dst, "w", encoding="utf-8", newline="\n").write("\n".join(out))
    msg = "ps2eeas_lis: %d li.s expanded" % expanded
    if skipped:
        msg += ", %d left in noreorder blocks" % skipped
    print(msg, src, "->", dst)


if __name__ == "__main__":
    main()
