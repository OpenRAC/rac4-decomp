"""Reader regressions for functions sharing data but occupying distinct sections."""
from contextlib import redirect_stdout
import io
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parent))
import audit_matches
from elf_test_objects import ElfSection, ElfSymbol, elf_bytes
import match_map
import retail
import try_func


FIRST = "func_00100000"
SECOND = "func_00100040"
FIRST_CODE = struct.pack("<III", 0x27820001, 0x03E00008, 0)
SECOND_CODE = struct.pack("<IIII", 0x24820002, 0x0C000000, 0x03E00008, 0)


def object_bytes(separate):
    if separate:
        sections = [ElfSection(".text", b""), ElfSection(".text.first", FIRST_CODE),
                    ElfSection(".text.second", SECOND_CODE), ElfSection(".sdata", b"\0", flags=3)]
        symbols = [ElfSymbol(FIRST, 2, 0, len(FIRST_CODE)), ElfSymbol(SECOND, 3, 0, len(SECOND_CODE)),
                   ElfSymbol("D_00200000", 4, 0, 1, symbol_type=1)]
        relocations = [(2, [(0, 7, 3)]), (3, [(4, 4, 1)])]
    else:
        sections = [ElfSection(".text", struct.pack("<I", 0xDEADBEEF) + FIRST_CODE + SECOND_CODE),
                    ElfSection(".sdata", b"\0", flags=3)]
        symbols = [ElfSymbol(FIRST, 1, 4, len(FIRST_CODE)),
                   ElfSymbol(SECOND, 1, 4 + len(FIRST_CODE), len(SECOND_CODE)),
                   ElfSymbol("D_00200000", 2, 0, 1, symbol_type=1)]
        relocations = [(1, [(4, 7, 3), (8 + len(FIRST_CODE), 4, 1)])]
    return elf_bytes(sections, symbols, relocations=relocations)


class FunctionReaderTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(prefix="rac4-function-readers-")
        self.root = Path(self.temp.name)
        (self.root / "config").mkdir()
        (self.root / "config/functions.tsv").write_text("")
        (self.root / "build/obj").mkdir(parents=True)
        self.obj = self.root / "build/obj/functions.o"

    def tearDown(self):
        self.temp.cleanup()

    def compiled_map(self):
        pattern = str(self.root / "build/obj" / "*.o")
        with patch.object(match_map, "ROOT", str(self.root)), \
                patch.object(match_map.glob, "glob", side_effect=lambda value: [str(self.obj)] if value == pattern else []):
            return match_map.compiled()

    def test_separate_sections_keep_bodies_and_relocations_distinct(self):
        self.obj.write_bytes(object_bytes(separate=True))
        first = try_func.compiled(self.obj, FIRST)
        second = try_func.compiled(self.obj, SECOND)
        self.assertEqual(first, (FIRST_CODE, {0: 0xFFFF}, 0))
        self.assertEqual(second, (SECOND_CODE, {4: 0x03FFFFFF}, 0))
        self.assertEqual(self.compiled_map(), {
            FIRST: (FIRST_CODE, {0: 0xFFFF}),
            SECOND: (SECOND_CODE, {4: 0x03FFFFFF}),
        })
        changed = struct.pack("<I", 0x24820003) + SECOND_CODE[4:]
        self.assertNotEqual(retail.fields(second[0], second[1], second[2]),
                            retail.fields(changed, second[1], second[2]))

    def test_ordinary_text_preserves_section_offsets_and_relative_map_masks(self):
        self.obj.write_bytes(object_bytes(separate=False))
        masks = {4: 0xFFFF, 8 + len(FIRST_CODE): 0x03FFFFFF}
        self.assertEqual(try_func.compiled(self.obj, FIRST), (FIRST_CODE, masks, 4))
        self.assertEqual(try_func.compiled(self.obj, SECOND), (SECOND_CODE, masks, 4 + len(FIRST_CODE)))
        self.assertEqual(self.compiled_map(), {
            FIRST: (FIRST_CODE, {0: 0xFFFF}),
            SECOND: (SECOND_CODE, {4: 0x03FFFFFF}),
        })

    def test_match_audit_does_not_borrow_another_functions_mask(self):
        self.obj.write_bytes(object_bytes(separate=True))
        (self.root / "config/functions.tsv").write_text(
            f"{FIRST}\t0x00100000\t0x{len(FIRST_CODE):X}\ttext\n"
            f"{SECOND}\t0x00100040\t0x{len(SECOND_CODE):X}\ttext\n")
        for name in ["overlay_functions.tsv", "overlays.tsv"]:
            (self.root / "config" / name).write_text("")
        (self.root / "baserom").mkdir()
        pattern = str(self.root / "build/obj" / "*.o")
        for changed in [False, True]:
            with self.subTest(changed=changed):
                second = struct.pack("<I", 0x24820003) + SECOND_CODE[4:] if changed else SECOND_CODE
                image = FIRST_CODE + bytes(0x40 - len(FIRST_CODE)) + second
                (self.root / "baserom/SCUS_974.65.elf").write_bytes(elf_bytes(
                    [ElfSection(".text", image, address=0x00100000)], [], elf_type=2))
                with patch.object(audit_matches, "ROOT", self.root), \
                        patch.object(audit_matches.glob, "glob", side_effect=lambda value: [str(self.obj)] if value == pattern else []), \
                        redirect_stdout(io.StringIO()):
                    result = audit_matches.main()
                expected = [FIRST] if changed else [FIRST, SECOND]
                self.assertEqual(json.loads((self.root / "build/matches.json").read_text())["exact"], expected)
                self.assertEqual(result, 0)


if __name__ == "__main__":
    unittest.main(verbosity=2)
