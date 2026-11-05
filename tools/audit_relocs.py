#!/usr/bin/env python3
"""
Check where the relocations of every exact function point.

tools/audit_matches.py masks the fields the linker fills in, so a function
that reads `D_00221FD1` where retail reads `D_00220B50`, or calls the wrong
function, still counts as exact. This tool resolves each relocation of an
exact function (build/matches.json) to the address a link would put there
and compares it with the address the retail instruction encodes:

- R_MIPS_26 (j/jal): the jump target;
- R_MIPS_HI16 + R_MIPS_LO16: the full address, %hi of the paired lui plus
  %lo of each access (a lui without an access is checked on its own);
- R_MIPS_GPREL16: $gp + offset, with retail's $gp = 0x22597F (and the
  object's own gp0 from .reginfo for its local symbols);
- R_MIPS_LITERAL: the literal value at the retail $gp address and its pool
  placement;
- R_MIPS_32 in .rodata (jump tables): each entry.

Addresses come from the symbol names (`func_XXXXXXXX`, `func_LNN_XXXXXXXX`,
`D_XXXXXXXX`, six or eight digits, with the `_`, `__gp` and `__lui` alias
suffixes), from config/libgcc.tsv and config/libm.tsv for the library
symbols (and config/library_callees.tsv for identified but unmatched helpers),
and for a file's own sections from the functions and the `D_` objects it
defines. A section with no named symbol (a jump table in
.rodata) gets the address retail implies; all its relocations must agree on
it. A shared overlay function is named after its address in its first level
(`func_L00_X`) but lies elsewhere in the others: a call to it from another
level counts if retail's target there has the same normalised code (the
function list gives all copies of one code one name, so a twin counts too).
Resident-function copies in levels must agree with the named placements in
config/us/functions.tsv.

The libraries (build/libgcc, build/libm) are verbatim GCC and newlib source
built by their own scripts: --libs checks them too. Their constant pools are
laid out differently from retail (the values are there), which shows up as
.rodata mismatches; the symbols they share with libc are not in any table.

Writes build/relocs.json and prints each mismatch: function, offset in the
function, relocation type, symbol, our address, retail's address and the
name retail's address would have. Exit status 1 on mismatches or unresolved
references.

Usage: venv/bin/python tools/audit_relocs.py [-v] [--libs] [func_name ...]
  (after tools/build.sh and tools/audit_matches.py)
"""
import glob
import io
import json
import os
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import retail as mp  # noqa: E402
import split_overlays as so  # noqa: E402
from elftools.elf.elffile import ELFFile  # noqa: E402

ROOT = mp.ROOT
GP = 0x22597F
R_32, R_26, R_HI16, R_LO16, R_GPREL16, R_LITERAL = 2, 4, 5, 6, 7, 8
NAME = re.compile(r"(?:func|D|jtbl)_(?:L\d\d_)?([0-9A-Fa-f]{6,8})(?:_|__gp|__lui)?")


def sext16(v):
    return v - 0x10000 if v & 0x8000 else v


def name_addr(name):
    m = NAME.fullmatch(name)
    return int(m.group(1), 16) if m else None


def load_tables():
    sizes = {}
    for l in (ROOT / "config" / "functions.tsv").read_text().splitlines():
        if l and not l.startswith("#"):
            n, a, s, _ = l.split("\t")
            sizes[n] = (int(a, 16), int(s, 16))
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
    alias, lib_syms = {}, {}
    by_addr = {a: n for n, (a, _) in sizes.items()}
    for tsv in ("libgcc.tsv", "libm.tsv"):
        lg = ROOT / "config" / tsv
        if lg.exists():
            for l in lg.read_text().splitlines():
                if l and not l.startswith("#"):
                    obj, sym, a, _ = l.split("\t")
                    alias[(obj[:-2] if obj.endswith(".o") else obj, sym)] = by_addr[int(a, 16)]
                    lib_syms[sym] = int(a, 16)
    # Identifying a library callee does not claim its source rebuild matches.
    callees = ROOT / "config" / "library_callees.tsv"
    if callees.exists():
        for line in callees.read_text().splitlines():
            if line and not line.startswith("#"):
                sym, addr = line.split("\t")
                lib_syms[sym] = int(addr, 16)
    return sizes, ovl, ovl_dirs, alias, lib_syms


class Checker:
    def __init__(self):
        self.sizes, self.ovl, self.ovl_dirs, self.alias, self.lib_syms = load_tables()
        with open(ROOT / "baserom" / "SCUS_974.65.elf", "rb") as f:
            self.secs = mp.sections(ELFFile(f))
        self.ovl_root = Path(os.environ.get("OVERLAYS") or ROOT / "private" / "overlays")
        self.ovl_secs = {}
        self.mismatches, self.unresolved, self.checked = [], [], 0
        self.by_code = {"unique": 0, "twin": 0, "catalogue": 0}
        self.digests = {}
        # The resident menu also occurs at different addresses in the levels.
        # Only the named copy at the catalogue's exact placement is accepted.
        import level_catalogue
        self.main_copies = {
            (name, "L%02d" % level): addr
            for name, kind, _, _, _, places in level_catalogue.read_catalogue(ROOT / "config/us/functions.tsv")
            if kind == "main"
            for level, addr in places
        }

    def overlay_secs(self, i):
        if i not in self.ovl_secs:
            p = self.ovl_root / "levels" / self.ovl_dirs[i] / "overlay.elf"
            self.ovl_secs[i] = mp.sections(ELFFile(open(p, "rb"))) if p.exists() else None
        return self.ovl_secs[i]

    def level_digests(self, lvl):
        """address -> digest of every function of one overlay, and how often each digest occurs"""
        if lvl not in self.digests:
            p = self.ovl_root / "levels" / self.ovl_dirs[lvl] / "overlay.elf"
            text = ELFFile(open(p, "rb")).get_section_by_name(".text")
            by_addr = {a: so.digest(code) for a, _, code in so.functions(text.data(), text["sh_addr"])}
            count = {}
            for d in by_addr.values():
                count[d] = count.get(d, 0) + 1
            self.digests[lvl] = by_addr, count
        return self.digests[lvl]

    def same_code(self, name, lvl, target):
        """A shared overlay function is named after its first level (func_L00_X)
        and lies elsewhere in the other levels. config/overlay_functions.tsv
        gives one name to all copies of one normalised code, so retail's target
        in level lvl is that function if it has that code: 'unique' if the code
        occurs once in each of the two levels, 'twin' otherwise, else None.
        A resident callee at its named US catalogue placement returns 'catalogue'."""
        if (name, lvl) in self.main_copies and self.main_copies[name, lvl] == target:
            return "catalogue"
        m = re.fullmatch(r"(func_L\d\d_[0-9A-F]{8})(?:_|__gp|__lui)?", name)
        if not m or m.group(1) not in self.ovl or lvl is None:
            return None
        own, addr, _ = self.ovl[m.group(1)]
        if own == lvl or self.overlay_secs(own) is None or self.overlay_secs(lvl) is None:
            return None
        a, ca = self.level_digests(own)
        b, cb = self.level_digests(lvl)
        d = a.get(addr)
        if d is None or b.get(target) != d:
            return None
        return "unique" if ca[d] == 1 and cb[d] == 1 else "twin"

    def place(self, name):
        """(retail address, retail sections) of a function name, or None."""
        if name in self.ovl:
            lvl, addr, _ = self.ovl[name]
            s = self.overlay_secs(lvl)
            return (addr, s) if s else None
        if name in self.sizes:
            return self.sizes[name][0], self.secs
        return None

    def check_object(self, path, exact, only):
        elf = ELFFile(io.BytesIO(Path(path).read_bytes()))
        symtab = elf.get_section_by_name(".symtab")
        sec_names = [s.name for s in elf.iter_sections()]
        syms = list(symtab.iter_symbols())
        text_idx = sec_names.index(".text") if ".text" in sec_names else None
        if text_idx is None:
            return
        text = elf.get_section(text_idx).data()
        # this file's functions: (start, end, our name, retail name, address, sections)
        funcs = []
        for s in syms:
            if s["st_info"]["type"] != "STT_FUNC" or s["st_shndx"] != text_idx:
                continue
            name = self.alias.get((Path(path).stem, s.name), s.name)
            p = self.place(name)
            if p:
                lvl = self.ovl[name][0] if name in self.ovl else None
                funcs.append((s["st_value"], s["st_value"] + s["st_size"], s.name, name, p[0], p[1], lvl))

        def func_at(off):
            for f in funcs:
                if f[0] <= off < f[1]:
                    return f
            return None

        # named objects this file defines, per section: (offset, size, address)
        defined = {}
        for s in syms:
            if isinstance(s["st_shndx"], int) and s["st_info"]["type"] in ("STT_OBJECT", "STT_NOTYPE"):
                a = name_addr(s.name)
                if a is not None:
                    defined.setdefault(s["st_shndx"], []).append((s["st_value"], s["st_size"], a))
        inferred = {}  # section index -> {implied base: [where]}
        # GPREL16 against a local symbol holds the offset minus the object's gp0
        reginfo = elf.get_section_by_name(".reginfo")
        gp0 = struct.unpack("<i", reginfo.data()[20:24])[0] if reginfo else 0

        def resolve(sym, off):
            """address of sym + off, or ('infer', section index, offset), or None"""
            shn = sym["st_shndx"]
            if sym["st_info"]["type"] == "STT_SECTION" or (isinstance(shn, int) and NAME.fullmatch(sym.name) is None):
                base = 0 if sym["st_info"]["type"] == "STT_SECTION" else sym["st_value"]
                if not isinstance(shn, int):
                    return None
                o = base + off
                if shn == text_idx:
                    f = func_at(o)
                    return f[4] + o - f[0] if f else None
                cands = [d for d in defined.get(shn, []) if d[0] <= o]
                if cands:
                    d = max(cands, key=lambda d: d[0])
                    return d[2] + o - d[0]
                return ("infer", shn, o)
            a = name_addr(sym.name)
            if a is None:
                a = self.lib_syms.get(sym.name)
            return None if a is None else a + off

        def report(f, off, typ, sym, ours, ret):
            if only and f[3] not in only:
                return
            self.checked += 1
            if isinstance(ours, tuple):
                # the section's base this relocation implies: retail's address minus our offset
                base = (ret - ours[2]) & 0xFFFFFFFF
                inferred.setdefault(ours[1], {}).setdefault(base, []).append((f, off, typ, sym))
                return
            if ours is None:
                self.unresolved.append({"function": f[3], "offset": off - f[0], "type": typ, "symbol": sym.name})
                return
            if ours != ret:
                self.mismatches.append({"function": f[3], "offset": off - f[0], "type": typ, "symbol": sym.name,
                                        "ours": ours, "retail": ret})

        def retail_word(f, off):
            b = mp.read(f[5], f[4] + off - f[0], 4)
            return struct.unpack("<I", b)[0]

        def our_word(off):
            return struct.unpack("<I", text[off:off + 4])[0]

        for rs in elf.iter_sections():
            if rs["sh_type"] != "SHT_REL" or rs["sh_info"] != text_idx:
                continue
            last_hi = {}  # symbol index -> offset of its latest HI16
            hi_used = {}
            for r in rs.iter_relocations():
                off, typ, si = r["r_offset"], r["r_info_type"], r["r_info_sym"]
                sym = syms[si]
                f = func_at(off)
                if typ == R_HI16:
                    last_hi[si] = off
                    hi_used[off] = False
                if f is None or f[3] not in exact:
                    continue
                w, rw = our_word(off), retail_word(f, off)
                if typ == R_26:
                    a = (w & 0x3FFFFFF) << 2
                    if sym["st_info"]["type"] != "STT_SECTION" and a & 0x8000000:
                        a -= 0x10000000
                    pc = f[4] + off - f[0]
                    ours, ret = resolve(sym, a), (pc & 0xF0000000) | ((rw & 0x3FFFFFF) << 2)
                    how = self.same_code(sym.name, f[6], ret) if ours != ret and a == 0 else None
                    if how:
                        self.by_code[how] += 1
                        ours = ret
                    report(f, off, "26", sym, ours, ret)
                elif typ == R_LO16:
                    h = last_hi.get(si)
                    if h is None:
                        report(f, off, "LO16", sym, None, None)
                        continue
                    hi_used[h] = True
                    a = ((our_word(h) & 0xFFFF) << 16) + sext16(w & 0xFFFF)
                    ret = ((((retail_word(f, h) & 0xFFFF) << 16) + sext16(rw & 0xFFFF)) & 0xFFFFFFFF)
                    report(f, off, "HI16/LO16", sym, resolve(sym, a), ret)
                elif typ == R_GPREL16:
                    a = sext16(w & 0xFFFF) + (gp0 if isinstance(sym["st_shndx"], int) else 0)
                    report(f, off, "GPREL16", sym, resolve(sym, a), (GP + sext16(rw & 0xFFFF)) & 0xFFFFFFFF)
                elif typ == R_LITERAL:
                    # GNU as places li.s/li.d constants in a local literal pool.
                    # Check the value, as well as consistent placement of that pool.
                    shn = sym["st_shndx"]
                    width = {0x31: 4, 0x35: 8}.get(w >> 26)  # lwc1, ldc1
                    a = sext16(w & 0xFFFF) + gp0
                    ret = (GP + sext16(rw & 0xFFFF)) & 0xFFFFFFFF
                    if (width is None or not isinstance(shn, int)
                            or sym["st_info"]["type"] != "STT_SECTION"):
                        report(f, off, "LITERAL", sym, None, ret)
                        continue
                    data = elf.get_section(shn).data()
                    value = data[a:a + width] if a >= 0 else b""
                    want = mp.read(f[5], ret, width)
                    if len(value) != width or want is None:
                        report(f, off, "LITERAL", sym, None, ret)
                        continue
                    report(f, off, "LITERAL", sym, ("infer", shn, a), ret)
                    if value != want and (not only or f[3] in only):
                        self.mismatches.append({"function": f[3], "offset": off - f[0], "type": "LITERAL",
                                                "symbol": sym.name, "ours": None, "retail": ret,
                                                "note": "literal value differs (%s vs %s)" % (value.hex(), want.hex())})
                elif typ != R_HI16:
                    report(f, off, "type%d" % typ, sym, None, None)
            # a lui no access uses: its %hi alone
            for r in rs.iter_relocations():
                off, si = r["r_offset"], r["r_info_sym"]
                if r["r_info_type"] != R_HI16 or hi_used.get(off):
                    continue
                f = func_at(off)
                if f is None or f[3] not in exact:
                    continue
                ours = resolve(syms[si], (our_word(off) & 0xFFFF) << 16)
                if isinstance(ours, int):
                    ours = (ours + 0x8000) >> 16 << 16
                report(f, off, "HI16", syms[si], ours, (retail_word(f, off) & 0xFFFF) << 16)

        # sections placed by retail: every relocation must imply the same base
        bases = {}
        for shn, by_base in inferred.items():
            if len(by_base) == 1:
                bases[shn] = next(iter(by_base))
                continue
            common = max(by_base, key=lambda b: len(by_base[b]))
            for b, wheres in by_base.items():
                if b != common:
                    for f, off, typ, sym in wheres:
                        self.mismatches.append({"function": f[3], "offset": off - f[0], "type": typ,
                                                "symbol": sym.name, "ours": None, "retail": b,
                                                "note": "%s placed at 0x%08X by the other relocations" % (sec_names[shn], common)})
            bases[shn] = common
        # jump tables: .rodata words relocated against .text
        for rs in elf.iter_sections():
            if rs["sh_type"] != "SHT_REL" or rs["sh_info"] == text_idx or rs["sh_info"] not in bases:
                continue
            shn = rs["sh_info"]
            data = elf.get_section(shn).data()
            for r in rs.iter_relocations():
                if r["r_info_type"] != R_32:
                    continue
                off, sym = r["r_offset"], syms[r["r_info_sym"]]
                ours = resolve(sym, struct.unpack("<I", data[off:off + 4])[0])
                # the function that loads the table
                user = next((f for f in funcs if f[3] in exact), None)
                if user is None or isinstance(ours, tuple):
                    continue
                if only and user[3] not in only:
                    continue
                b = mp.read(user[5], bases[shn] + off, 4)
                ret = struct.unpack("<I", b)[0] if b else None
                self.checked += 1
                if ours != ret:
                    self.mismatches.append({"function": user[3], "offset": None, "type": "32 (%s+0x%X)" % (sec_names[shn], off),
                                            "symbol": sym.name, "ours": ours, "retail": ret})


def main() -> int:
    args = [a for a in sys.argv[1:] if not a.startswith("-")]
    verbose = "-v" in sys.argv
    exact = set(json.loads((ROOT / "build" / "matches.json").read_text())["exact"])
    c = Checker()
    paths = glob.glob(str(ROOT / "build" / "obj" / "*.o"))
    if "--libs" in sys.argv:
        paths += glob.glob(str(ROOT / "build" / "libgcc" / "*.o")) + glob.glob(str(ROOT / "build" / "libm" / "*.o"))
    for path in sorted(paths):
        c.check_object(path, exact, set(args))
    (ROOT / "build" / "relocs.json").write_text(json.dumps({"mismatches": c.mismatches, "unresolved": c.unresolved}, indent=1))
    funcs = sorted({m["function"] for m in c.mismatches})
    print("%d relocations checked in %d exact functions (calls to shared overlay functions in another level,"
          " found by their code: %d unique, %d twins; catalogued resident copies: %d): "
          "%d mismatches in %d functions, %d unresolved"
          % (c.checked, len(exact), c.by_code["unique"], c.by_code["twin"], c.by_code["catalogue"], len(c.mismatches), len(funcs),
             len(c.unresolved)))

    def hx(v):
        return "?" if v is None else "0x%08X" % v
    for m in c.mismatches:
        off = "" if m["offset"] is None else "+0x%X" % m["offset"]
        name = "" if m["retail"] is None or m["type"].startswith("32") else \
            " (%s_%08X)" % ("func" if m["type"] == "26" else "D", m["retail"])
        print("  %s%s %s %s: ours %s, retail %s%s%s" % (
            m["function"], off, m["type"], m["symbol"], hx(m["ours"]), hx(m["retail"]), name,
            "  " + m["note"] if "note" in m else ""))
    if verbose or len(c.unresolved) <= 20:
        for u in c.unresolved:
            print("  unresolved: %s+0x%X %s %s" % (u["function"], u["offset"], u["type"], u["symbol"]))
    return 1 if c.mismatches or c.unresolved else 0


if __name__ == "__main__":
    raise SystemExit(main())
