"""PAL native relocation checks with synthetic MIPS objects, without game data."""
from io import BytesIO
from pathlib import Path
import struct
import unittest

from elftools.elf.elffile import ELFFile

import audit_pal_relocs as pal
import audit_relocs
from elf_test_objects import ElfSection, ElfSymbol, elf_bytes


FUNCTION = "func_L01_00001000"
CALLEE = "func_L00_00003000"
DATA = "D_002214E0"
PAL_GP = 0x2259FF


def words(*values):
    return struct.pack("<%dI" % len(values), *values)


def check(payload, retail, catalogue):
    row = {"name": FUNCTION, "places": [("level_01", ".text", 0x1000, len(retail))]}
    checker = pal.PalChecker([row], catalogue=catalogue, gp=PAL_GP)
    checker.sections = lambda _: [(0x1000, len(retail), ".text", retail)]
    checker.check_elf(ELFFile(BytesIO(payload)), Path("synthetic.o"), {FUNCTION}, set())
    return checker


class PalNativeRelocationTests(unittest.TestCase):
    def test_shared_callee_uses_its_address_in_callers_level(self):
        payload = elf_bytes(
            [ElfSection(".text", words(0x0C000000))],
            [ElfSymbol(FUNCTION, 1, 0, 4), ElfSymbol(CALLEE, 0, 0, 0)],
            relocations=[(1, [(0, audit_relocs.R_26, 2)])],
        )
        catalogue = [(CALLEE, "shared", 4, "", False, [(0, 0x3000), (1, 0x2000)])]
        result = check(payload, words(0x0C000800), catalogue)
        self.assertEqual(result.checked, 1)
        self.assertEqual(result.mismatches, [])
        self.assertEqual(result.unresolved, [])

    def test_wrong_callee_is_reported(self):
        wrong = "func_L00_00004000"
        payload = elf_bytes(
            [ElfSection(".text", words(0x0C000000))],
            [ElfSymbol(FUNCTION, 1, 0, 4), ElfSymbol(wrong, 0, 0, 0)],
            relocations=[(1, [(0, audit_relocs.R_26, 2)])],
        )
        result = check(payload, words(0x0C000800), [])
        self.assertEqual(result.checked, 1)
        self.assertEqual(result.mismatches, [{
            "function": FUNCTION, "offset": 0, "type": "26", "symbol": wrong,
            "ours": 0x4000, "retail": 0x2000,
        }])

    def test_wrong_global_is_reported(self):
        wrong = "D_002214E8"
        payload = elf_bytes(
            [ElfSection(".text", words(0x27820000))],
            [ElfSymbol(FUNCTION, 1, 0, 4), ElfSymbol(wrong, 0, 0, 0)],
            relocations=[(1, [(0, audit_relocs.R_GPREL16, 2)])],
        )
        retail = words(0x27820000 | ((0x2214E0 - PAL_GP) & 0xFFFF))
        result = check(payload, retail, [])
        self.assertEqual(result.checked, 1)
        self.assertEqual(result.mismatches, [{
            "function": FUNCTION, "offset": 0, "type": "GPREL16", "symbol": wrong,
            "ours": 0x2214E8, "retail": 0x2214E0,
        }])

    def test_pal_gp_value_accepts_correct_global(self):
        payload = elf_bytes(
            [ElfSection(".text", words(0x27820000))],
            [ElfSymbol(FUNCTION, 1, 0, 4), ElfSymbol(DATA, 0, 0, 0)],
            relocations=[(1, [(0, audit_relocs.R_GPREL16, 2)])],
        )
        retail = words(0x27820000 | ((0x2214E0 - PAL_GP) & 0xFFFF))
        result = check(payload, retail, [])
        self.assertEqual(result.checked, 1)
        self.assertEqual(result.mismatches, [])

    def test_object_path_uses_build_layout(self):
        self.assertEqual(pal.object_path({"file": "src/pal/overlays/shared/L01_0043A2C8.c"}),
                         pal.ROOT / "build/obj/pal_overlays_shared_L01_0043A2C8.o")


if __name__ == "__main__":
    unittest.main()
