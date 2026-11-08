#!/usr/bin/env python3
"""inventory.py: every function of the programs of one disc, found from the binaries alone.

    python3 tools/inventory.py [--version us|pal]           # the counts
    python3 tools/inventory.py [--version us|pal] --write   # config/<version>/inventory.tsv

Adapted from rac3-uya-decomp-pal's tools/inventory.py (b20190e), which ports rac1-decomp's
methods (tools/overlays.py split(), code_size(); tools/overlay_remnants.py); the rules are
unchanged, only the programs are Deadlocked's. They are applied the same way to every code
section: the main image's core.text, net.text and resident .text (the menus), frontbin's
.text and the .text of the level programs (tools/levels.py dump). .vutext is VU microcode, not
EE code, and is not counted (rac3 does the same). net.text is the same in every program (the
dumps carry it): it is counted once, in the main image. Nothing is taken from another
decompilation's lists or from splat.

Function starts (split()):
  - the start of the section, the entry point, and every jal (or bgezal/bltzal) target inside it;
  - the instruction after a `jr $ra` and its delay slot, skipping the zero words after it;
  - after a `j` and its delay slot, when what follows the zero words is a frame opener
    (`addiu $sp, $sp, -N`): a tail call that ends a function;
  - a frame opener right after a zero word (a function the alignment padding precedes);
  - a pointer in the program's data that points just after finished code; the lvl.* tables'.

Joined (rac1-decomp's joined.tsv rule, from the bytes): a conditional branch never leaves its
function, so a start that one crosses is not a start, unless a call or a dispatch table
reaches it.

Proven: where C in src/ builds to a function's bytes (config/<version>/map.tsv, tools/match_map.py),
the function starts and ends where that C does.

A function's size is its bytes without the zero words after it, but with the nop in the delay
slot of its last jump (code_size()); the zero words are padding, not code. An entry made only of
zero words or linker fill (0xCDCDCDCD) is padding, not a function.

Linker remnants (rac1-decomp's rule, docs/ASM_CLASSIFICATION.md there): what the linker left of a
function it stripped, its last word. An entry is a remnant when, in its program:
  - it starts on an 8-byte boundary, and every word of it is either zero or fill, or a word that
    is not a jump or branch (no delay slot), with at least one such word;
  - the code before it is finished: going back over earlier remnants, there is a `jr $ra` and
    its delay slot, a `j` and its delay slot, or the start of the section;
  - nothing reaches it: no branch or jump lands on one of its words, and no word of the
    program (code or data) holds one of their addresses.
Remnants are counted as functions, as rac1-decomp counts them (finished original bytes).
"""
import argparse
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import levels  # noqa: E402

JR_RA = 0x03E00008
FILL = 0xCDCDCDCD


def words(b):
    return struct.unpack("<%dI" % (len(b) // 4), b[:len(b) // 4 * 4])


def is_frame_opener(x):
    return x >> 16 == 0x27BD and x & 0x8000


def split(w, base, extra=()):
    """rac1-decomp's split(): [(word index, word count)] of each entry of a code section."""
    n = len(w)
    starts = {0} | {(a - base) // 4 for a in extra if base <= a < base + 4 * n}
    for i, x in enumerate(w):
        if x >> 26 == 3:
            t = ((x & 0x3FFFFFF) << 2) | (base & 0xF0000000)
            if base <= t < base + 4 * n:
                starts.add((t - base) // 4)
        elif is_branch_link(x):
            t = branch_target(x, base + 4 * i)
            if base <= t < base + 4 * n:
                starts.add((t - base) // 4)
        if (x == JR_RA or x >> 26 == 2) and i + 2 < n:
            j = i + 2
            while j < n and w[j] == 0:
                j += 1
            if x == JR_RA or (j < n and is_frame_opener(w[j])):
                starts.add(j)
        if is_frame_opener(x) and i and w[i - 1] == 0:
            starts.add(i)
    s = sorted(x for x in starts if x < n)
    return [(a, b - a) for a, b in zip(s, s[1:] + [n])]


def is_branch_link(x):
    """bltzal, bgezal, bltzall, bgezall: a call (the hand-written VU0 routines call this way)."""
    return x >> 26 == 1 and (x >> 16) & 0x1F in (0x10, 0x11, 0x12, 0x13)


def ends_in_jump(x):
    """jr, j or b (beq $0, $0): a last instruction whose delay slot follows it."""
    return (x & 0xFC1FFFFF) == 0x00000008 or x >> 26 == 2 or x >> 16 == 0x1000


def code_words(ws):
    """rac1-decomp's code_size(), in words."""
    k = len(ws)
    while k and ws[k - 1] == 0:
        k -= 1
    if k < len(ws) and k and ends_in_jump(ws[k - 1]):
        return k + 1
    return k


def has_delay_slot(x):
    """A jump or branch: its next word is a delay slot."""
    op = x >> 26
    if op == 0:
        return x & 0x3F in (0x08, 0x09)                    # jr, jalr
    if op == 1:
        return (x >> 16) & 0x1F in (0, 1, 2, 3, 0x10, 0x11, 0x12, 0x13)   # bltz.. bgezall
    if op in (2, 3) or 4 <= op <= 7 or 0x14 <= op <= 0x17:
        return True
    if op in (0x11, 0x12) and (x >> 21) & 0x1F == 8:         # bc1x, bc2x
        return True
    return False


def branch_target(x, addr):
    op = x >> 26
    if op in (2, 3):
        return ((addr + 4) & 0xF0000000) | ((x & 0x3FFFFFF) << 2)
    if (op == 1 and (x >> 16) & 0x1F in (0, 1, 2, 3, 0x10, 0x11, 0x12, 0x13)) or 4 <= op <= 7 or \
            0x14 <= op <= 0x17 or (op in (0x11, 0x12) and (x >> 21) & 0x1F == 8):
        off = x & 0xFFFF
        off -= 0x10000 if off & 0x8000 else 0
        return addr + 4 + 4 * off
    return None


class Section:
    def __init__(self, program, name, base, data, others=()):
        self.program, self.name, self.base = program, name, base
        self.w = words(data)
        self.others = others            # every other loaded section's words (pointers in data)
        self.vtable = set()             # function pointers of the lvl.* dispatch tables
        self.entry = None               # the program's entry point, when it is in this section

    def entries(self, extra=(), proven=None):
        """[(address, size, kind)] kind: "function" or "remnant"; padding left out. EXTRA:
        addresses that start a function whatever else holds. PROVEN: {start: end} of functions
        whose extent a byte-identical build of their C proves: no start inside one."""
        w, base = self.w, self.base
        proven = proven or {}
        extra = set(extra) | set(proven) | ({self.entry} if self.entry else set())
        # a function pointer in the program's data (outside the dispatch tables) that points just
        # after finished code (a return or jump and its delay slot, then zero words) starts one;
        # the join below still applies to it (a jump table's case can look the same)
        lo, hi = base, base + 4 * len(w)
        after = set()
        for ws in self.others:
            for x in ws:
                if lo < x < hi and not x & 3:
                    k = (x - base) // 4 - 1
                    while k > 0 and w[k] == 0:
                        k -= 1
                    # the jump in w[k] needs a zero delay slot before x: right after it, x is
                    # its delay slot (a data word that only looks like a pointer)
                    if k >= 1 and (w[k - 1] == JR_RA or w[k - 1] >> 26 == 2 or
                                   ((w[k] == JR_RA or w[k] >> 26 == 2) and k < (x - base) // 4 - 1)):
                        after.add(x)
        raw = split(w, base, set(extra) | after | self.vtable)
        # A proved function end can precede linker padding. Do not turn that
        # padding into an unaligned function containing the following remnant.
        # Keep independently discovered entries, including entries at nops.
        starts = {a for a, _ in raw}
        for end in proven.values():
            at = (end - base) // 4
            if not 0 <= at < len(w):
                continue
            while at < len(w) and w[at] in (0, FILL) and at not in starts:
                at += 1
            if at < len(w):
                starts.add(at)
                extra.add(base + 4 * at)
        ordered = sorted(starts)
        raw = [(a, b - a) for a, b in zip(ordered, ordered[1:] + [len(w)])]
        if proven:
            spans = sorted(proven.items())
            import bisect
            keys = [a for a, _ in spans]
            def inside(x):
                i = bisect.bisect_right(keys, x) - 1
                return i >= 0 and keys[i] < x < spans[i][1]
            merged = []
            for a, n in raw:
                if merged and inside(base + 4 * a):
                    merged[-1] = (merged[-1][0], merged[-1][1] + n)
                else:
                    merged.append((a, n))
            raw = merged
        self.protected = set(extra)
        reached = set()
        for i, x in enumerate(w):
            t = branch_target(x, base + 4 * i)
            if t is not None:
                reached.add(t)
        lo, hi = base, base + 4 * len(w)
        pointed = {x for x in w if lo <= x < hi and not x & 3}
        for ws in self.others:
            pointed |= {x for x in ws if lo <= x < hi and not x & 3}
        raw = self.joined(raw, pointed)
        out = []
        for a, n in raw:
            ws = w[a:a + n]
            if all(x in (0, FILL) for x in ws):
                continue
            out.append([base + 4 * a, ws])
        result = []
        for k, (addr, ws) in enumerate(out):
            size = 4 * code_words(ws) if any(ws) else 4 * len(ws)
            kind = "function"
            if self.is_remnant(addr, ws, result, reached, pointed):
                kind = "remnant"
                size = 4 * code_words_plain(ws)
            result.append((addr, size, kind))
        return result

    def joined(self, raw, pointed):
        """Joined functions (rac1-decomp's config/overlays/joined.tsv rule, applied from the
        bytes): a conditional branch never leaves its function, so a start that one crosses (a
        branch before it to after it, or after it back to before it) is not a function start,
        unless a jal reaches it or a dispatch table points at it. Such a piece is an early
        return, a trap block or a loop after a return of the function before it."""
        w, base = self.w, self.base
        n = len(w)
        jal = set()
        cover = [0] * (n + 2)
        for i, x in enumerate(w):
            if x >> 26 == 3:
                jal.add(((x & 0x3FFFFFF) << 2) | (base & 0xF0000000))
            elif is_branch_link(x):
                jal.add(branch_target(x, base + 4 * i))
            elif x >> 26 != 2:
                t = branch_target(x, base + 4 * i)
                if t is not None and base <= t < base + 4 * n:
                    j = (t - base) // 4
                    lo, hi = min(i, j), max(i, j)
                    cover[lo + 1] += 1
                    cover[hi + 1] -= 1
        crossed, c = [False] * (n + 1), 0
        for k in range(n + 1):
            c += cover[k]
            crossed[k] = c > 0
        out = []
        for a, m in raw:
            addr = base + 4 * a
            if out and crossed[a] and addr not in jal and addr not in self.vtable and addr not in self.protected:
                pa, pn = out[-1]
                out[-1] = (pa, pn + m)
                continue
            out.append((a, m))
        return out

    def is_remnant(self, addr, ws, before, reached, pointed):
        if addr % 8:
            return False
        if not any(x not in (0, FILL) for x in ws):
            return False
        for i, x in enumerate(ws):
            if x in (0, FILL):
                continue
            if has_delay_slot(x):
                return False
        n = len(ws)
        if any(addr + 4 * i in reached or addr + 4 * i in pointed for i in range(n)):
            return False
        # the code before it is finished
        k = (addr - self.base) // 4
        if k == 0:
            return True
        j = k - 1
        while j >= 0 and self.w[j] in (0, FILL):
            j -= 1
        # back over earlier remnants
        rem = [(a, a + n) for a, n, kind in before if kind == "remnant"]
        while j >= 0:
            at = self.base + 4 * j
            r = next((r for r in reversed(rem) if r[0] <= at < r[1]), None)
            if r is None:
                break
            j = (r[0] - self.base) // 4 - 1
            while j >= 0 and self.w[j] in (0, FILL):
                j -= 1
        if j < 1:
            return j < 0
        # a return or jump whose delay slot is the word after it, or was a nop (skipped above)
        last, prev = self.w[j], self.w[j - 1]
        return prev == JR_RA or prev >> 26 == 2 or last == JR_RA or last >> 26 == 2


def code_words_plain(ws):
    k = len(ws)
    while k and ws[k - 1] in (0, FILL):
        k -= 1
    return k


def elf_sections(path):
    """[(name, address, bytes)] of a dump's loaded sections with file bytes."""
    _, secs = levels.read_elf(open(path, "rb").read())
    return [(name, a, b) for name, a, n, k, b in secs if a and k != 8]


# the code sections counted, per program kind (.vutext is VU microcode)
CORE = {"main": ["core.text", "net.text", ".text"], "frontbin": [".text"]}


def program_sections(program, path, code_names):
    secs = elf_sections(path)
    data = open(path, "rb").read()
    entry = struct.unpack_from("<I", data, 0x18)[0]
    out = []
    for name, base, b in secs:
        if name in code_names:
            others = [words(d) for n, _, d in secs if n != name]
            sec = Section(program, name, base, b, others)
            for n, _, d in secs:
                if n.startswith("lvl."):
                    sec.vtable |= set(words(d))
            if base <= entry < base + len(b):
                sec.entry = entry
            out.append(sec)
    return out


def distinct_levels():
    """The level numbers whose program is not a byte-identical copy of a lower one."""
    return [r["number"] for r in levels.read_table() if r["copy_of"] == r["number"]]


# --- identity: what two copies of a function share (rac2-decomp's tools/levels.py identity()) ---

MEM = {0x1A, 0x1B, 0x1E, 0x1F, *range(0x20, 0x30), 0x31, 0x36, 0x37, 0x39, 0x3E, 0x3F}
# Every level program and frontbin replace the memory from the lowest .lit (0x21E180 on the US
# disc, 0x21E200 on PAL); below it,
# the engine core's code and data are resident and the same for all, and so is net.text
# (0x1E9A000.., the same bytes in every program) with the memory after it.
RESIDENT_ENDS = {"us": 0x21E180, "pal": 0x21E200}   # the lowest .lit of each disc's programs
NET_TEXT = 0x1E9A000


def is_resident(a):
    return a < RESIDENT_ENDS[levels.V] or a >= NET_TEXT


def identity(b, address=0):
    """The words of one function with only its address fields masked: jump targets, the high
    half of a RAM address (lui), $gp offsets and the offsets on a register that holds an address.
    Every other immediate is compared, so two routines that differ in a constant, a stack slot
    or a field offset stay two functions. Jumps and address halves into the resident core are
    compared too: they are the same in every program. ADDRESS is the function's start."""
    w = list(words(b))
    while w and w[-1] == 0:
        w.pop()
    hi = RESIDENT_ENDS[levels.V] >> 16
    net_hi = NET_TEXT >> 16
    tainted, grew = set(), True
    while grew:
        grew = False
        for x in w:
            op, rs, rt, rd = x >> 26, (x >> 21) & 31, (x >> 16) & 31, (x >> 11) & 31
            new = None
            if op == 0x0F and 0x10 <= x & 0xFFFF < 0x200:
                new = rt
            elif op in (0x09, 0x19) and rs in tainted:
                new = rt
            elif op == 0 and x & 0x3F in (0x21, 0x2D, 0x25) and (rs in tainted or rt in tainted):
                new = rd
            if new and new not in tainted:
                tainted.add(new)
                grew = True
    out, resident = [], {}
    for k, x in enumerate(w):
        op, rs, rt, imm = x >> 26, (x >> 21) & 31, (x >> 16) & 31, x & 0xFFFF
        if op in (2, 3):
            target = ((address + 4 * k) & 0xF0000000) | ((x & 0x3FFFFFF) << 2)
            if not (address and is_resident(target)):
                x &= 0xFC000000
        elif op == 0x0F:
            resident[rt] = 0x10 <= imm < hi or net_hi <= imm < 0x200
            if 0x10 <= imm < 0x200 and not resident[rt]:
                x &= 0xFFFF0000
        elif rs in resident and resident[rs] and (op in MEM or op in (0x09, 0x0D, 0x19)) and rs != 29:
            pass
        elif rs == 28 and op >= 8:
            x &= 0xFFFF0000
        elif (op in MEM or op in (0x09, 0x0D, 0x19)) and rs != 29:
            small = imm < 0x1000 or imm >= 0xF000
            if rs in tainted or (rs != 0 and op != 0x0D and not small):
                x &= 0xFFFF0000
        out.append(x)
    return struct.pack("<%dI" % len(out), *out)


def fingerprint(b, address=0):
    import hashlib
    return hashlib.sha1(identity(b, address)).hexdigest()[:16]


def proven_extents(program):
    """{section: {start: end}} of the functions C in src/ builds to (config/<version>/map.tsv)."""
    import match_map
    out = {}
    for row in match_map.read_map():
        if row["status"] == "match":
            for prog, sec, a, n in row["places"]:
                if prog == program:
                    out.setdefault(sec, {})[a] = a + n
    return out


def core_inventory():
    """[(program, section, address, size, kind)] of main and frontbin."""
    rows = []
    for prog, names in CORE.items():
        proven = proven_extents(prog)
        for s in program_sections(prog, levels.program_path(prog), names):
            for addr, size, kind in s.entries(proven=proven.get(s.name)):
                rows.append((prog, s.name, addr, size, kind))
    return rows


def read_inventory(path=None):
    """{program: [(section, address, size, kind)]} from config/<version>/inventory.tsv."""
    out = {}
    for line in open(path or levels.cfg("inventory.tsv")):
        if line.startswith("#") or not line.strip():
            continue
        prog, sec, a, n, kind = line.rstrip("\n").split("\t")
        out.setdefault(prog, []).append((sec, int(a, 16), int(n), kind))
    return out


HEAD = """# Every function of the %s main image (core.text, net.text, the resident menu .text) and of
# frontbin's .text, found from the binaries (tools/inventory.py --write): program, section,
# address, size in bytes (without the padding after it), kind (function or remnant).
"""


def main():
    levels.cli_version()
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true", help="rewrite config/<version>/inventory.tsv")
    a = ap.parse_args()
    rows = core_inventory()
    by = {}
    for r in rows:
        by.setdefault((r[0], r[1]), []).append(r)
    for (p, s), rs in by.items():
        print("%s %s: %d functions (%d of them linker remnants), %d bytes of code"
              % (p, s, len(rs), sum(1 for r in rs if r[4] == "remnant"), sum(r[3] for r in rs)))
    print("main and frontbin: %d functions, %d bytes" % (len(rows), sum(r[3] for r in rows)))
    if a.write:
        with open(levels.cfg("inventory.tsv"), "w", newline="\n") as f:
            f.write(HEAD % levels.version_id())
            for r in rows:
                f.write("%s\t%s\t%08X\t%d\t%s\n" % r)
        print("wrote", os.path.relpath(levels.cfg("inventory.tsv"), ROOT))


if __name__ == "__main__":
    main()
