"""Relocation ownership regressions using synthetic MIPS objects, not game data."""
from io import BytesIO
from pathlib import Path
import struct
import unittest

from elftools.elf.elffile import ELFFile

import audit_relocs as audit
from elf_test_objects import ElfSection, ElfSymbol, elf_bytes


FIRST = "func_00001000"
SECOND = "func_00002000"
MARKER = 0x00222220


def words(*values):
    return struct.pack("<%dI" % len(values), *values)


def checker(placements):
    result = audit.Checker.__new__(audit.Checker)
    result.alias, result.ovl, result.lib_syms = {}, {}, {}
    result.mismatches, result.unresolved, result.checked = [], [], 0
    result.by_code = {"unique": 0, "twin": 0}
    result.place = placements.get
    return result


def section(address, data):
    return (address, len(data), ".text", data)


def shared_marker_object(*, split=True, wrong_callee=False, marker=MARKER):
    """One call and two accesses to the same data owner, with colliding offsets."""
    gp_word = 0x27820000 | ((MARKER - audit.GP) & 0xFFFF)
    retail = [section(0x1000, words(0x0C000800, gp_word)),
              section(0x2000, words(gp_word))]
    if split:
        sections = [ElfSection(".text", b""),
                    ElfSection(".text.first", words(0x0C000000, 0x27820000)),
                    ElfSection(".text.second", words(0x27820000)),
                    ElfSection(".sdata", b"\0", flags=3)]
        symbols = [ElfSymbol(FIRST, 2, 0, 8), ElfSymbol(SECOND, 3, 0, 4),
                   ElfSymbol("", 2, 0, 0, 3), ElfSymbol("", 3, 0, 0, 3),
                   ElfSymbol("", 4, 0, 0, 3), ElfSymbol("D_%08X" % marker, 4, 0, 1, 1)]
        call_symbol = 3 if wrong_callee else 4
        relocations = [(2, [(0, audit.R_26, call_symbol), (4, audit.R_GPREL16, 5)]),
                       (3, [(0, audit.R_GPREL16, 5)])]
    else:
        # Offsets deliberately differ from retail addresses and from zero.
        sections = [ElfSection(".text", words(0, 0x0C000003, 0x27820000, 0x27820000)),
                    ElfSection(".sdata", b"\0", flags=3)]
        symbols = [ElfSymbol(FIRST, 1, 4, 8), ElfSymbol(SECOND, 1, 12, 4),
                   ElfSymbol("", 1, 0, 0, 3), ElfSymbol("", 2, 0, 0, 3),
                   ElfSymbol("D_%08X" % marker, 2, 0, 1, 1)]
        relocations = [(1, [(4, audit.R_26, 3), (8, audit.R_GPREL16, 4),
                            (12, audit.R_GPREL16, 4)])]
    return elf_bytes(sections, symbols, relocations=relocations), {
        FIRST: (0x1000, retail), SECOND: (0x2000, retail)
    }


class FunctionSectionRelocationTests(unittest.TestCase):
    def check(self, payload, placements):
        result = checker(placements)
        result.check_elf(ELFFile(BytesIO(payload)), Path("synthetic.o"), set(placements), set())
        return result

    def test_split_functions_and_legacy_text_resolve_identically(self):
        for split in (False, True):
            with self.subTest(split=split):
                result = self.check(*shared_marker_object(split=split))
                self.assertEqual(result.checked, 3)
                self.assertEqual(result.mismatches, [])
                self.assertEqual(result.unresolved, [])

    def test_wrong_section_callee_is_not_hidden_by_offset_zero(self):
        result = self.check(*shared_marker_object(wrong_callee=True))
        self.assertEqual(result.checked, 3)
        self.assertEqual(result.unresolved, [])
        self.assertEqual(result.mismatches, [{
            "function": FIRST, "offset": 0, "type": "26", "symbol": "",
            "ours": 0x1000, "retail": 0x2000,
        }])

    def test_wrong_shared_data_owner_is_reported_for_both_functions(self):
        result = self.check(*shared_marker_object(marker=MARKER + 4))
        self.assertEqual(result.checked, 3)
        self.assertEqual(result.unresolved, [])
        self.assertEqual({(row["function"], row["offset"], row["type"], row["ours"], row["retail"])
                          for row in result.mismatches}, {
            (FIRST, 4, "GPREL16", MARKER + 4, MARKER),
            (SECOND, 0, "GPREL16", MARKER + 4, MARKER),
        })

    def test_hi_lo_pairs_do_not_cross_function_sections(self):
        sections = [ElfSection(".text.first", words(0x3C080000)),
                    ElfSection(".text.second", words(0x25080000))]
        symbols = [ElfSymbol(FIRST, 1, 0, 4), ElfSymbol(SECOND, 2, 0, 4),
                   ElfSymbol("D_%08X" % MARKER, 0, 0, 0, 0)]
        payload = elf_bytes(sections, symbols, relocations=[
            (1, [(0, audit.R_HI16, 3)]), (2, [(0, audit.R_LO16, 3)]),
        ])
        placements = {
            FIRST: (0x1000, [section(0x1000, words(0x3C080022))]),
            SECOND: (0x2000, [section(0x2000, words(0x25082220))]),
        }
        result = self.check(payload, placements)
        self.assertEqual(result.checked, 2)
        self.assertEqual(result.mismatches, [])
        self.assertEqual(result.unresolved, [{
            "function": SECOND, "offset": 0, "type": "LO16", "symbol": "D_%08X" % MARKER,
        }])

    def test_jump_table_uses_its_proving_function_and_target_section(self):
        sections = [ElfSection(".text.first", words(0)),
                    ElfSection(".text.second", words(0x3C080000, 0x25080000)),
                    ElfSection(".rodata", words(0), flags=2)]
        symbols = [ElfSymbol(FIRST, 1, 0, 4), ElfSymbol(SECOND, 2, 0, 8),
                   ElfSymbol("", 2, 0, 0, 3), ElfSymbol("", 3, 0, 0, 3)]
        payload = elf_bytes(sections, symbols, relocations=[
            (2, [(0, audit.R_HI16, 4), (4, audit.R_LO16, 4)]),
            (3, [(0, audit.R_32, 3)]),
        ])
        # Only SECOND's retail image owns the table; using FIRST would fail.
        placements = {
            FIRST: (0x1000, [section(0x1000, words(0))]),
            SECOND: (0x2000, [section(0x2000, words(0x3C080000, 0x25083000)),
                              (0x3000, 4, ".rodata", words(0x2000))]),
        }
        result = self.check(payload, placements)
        self.assertEqual(result.checked, 2)
        self.assertEqual(result.mismatches, [])
        self.assertEqual(result.unresolved, [])


if __name__ == "__main__":
    unittest.main()
