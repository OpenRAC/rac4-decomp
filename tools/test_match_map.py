"""Native map updates validate complete translation units before replacing rows."""
from contextlib import redirect_stderr, redirect_stdout
import io
from pathlib import Path
import stat
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parent))
import check_func
from elf_test_objects import ElfSection, ElfSymbol, elf_bytes
import gen_progress_report
import levels
import match_map


FIRST = "func_00100000"
SECOND = "func_00100040"
FIRST_CODE = struct.pack("<III", 0x27820001, 0x03E00008, 0)
SECOND_CODE = struct.pack("<IIII", 0x24820002, 0x0C000000, 0x03E00008, 0)
UNRELATED = (b"# retain this header\r\n"
             b"func_00900000\tsrc/game/00900000.c\tmatch\tfunc_00900000\tmain:.text:00900000:4\t100.000\r\n"
             b"# retain this footer\r\n")


def grouped_object(second=SECOND_CODE):
    return elf_bytes(
        [ElfSection(".text", b""), ElfSection(".text.first", FIRST_CODE),
         ElfSection(".text.second", second), ElfSection(".sdata", b"\0", flags=3)],
        [ElfSymbol(FIRST, 2, 0, len(FIRST_CODE)), ElfSymbol(SECOND, 3, 0, len(second)),
         ElfSymbol("D_00200000", 4, 0, 1, symbol_type=1)],
        relocations=[(2, [(0, 7, 3)]), (3, [(4, 4, 1)])])


class NativeUpdateTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(prefix="rac4-native-map-")
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.addCleanup(levels.select, levels.V)
        self.definitions = {}
        self.tables = {version: {} for version in ["us", "pal"]}
        self.discs = {version: {} for version in ["us", "pal"]}
        for version in ["us", "pal"]:
            (self.root / "config" / version).mkdir(parents=True)
            (self.root / "config" / version / "map.tsv").write_bytes(UNRELATED)
        (self.root / "config/functions.tsv").write_text("")
        self.patches = [patch.object(match_map, "ROOT", str(self.root)),
                        patch.object(levels, "ROOT", str(self.root)),
                        patch.object(gen_progress_report, "source_functions", side_effect=lambda: self.definitions),
                        patch.object(check_func, "places", side_effect=lambda: self.tables[levels.V]),
                        patch.object(check_func, "disc_bytes", side_effect=lambda place: self.discs[levels.V][tuple(place)])]
        for item in self.patches:
            item.start()
            self.addCleanup(item.stop)

    def prepare(self, native="pal", active=None, object_present=True, second=SECOND_CODE):
        levels.select(active or native)
        relative = "src/pal/game/grouped.c" if native == "pal" else "src/game/grouped.c"
        self.source = self.root / relative
        self.source.parent.mkdir(parents=True, exist_ok=True)
        self.source.write_text(f"void {FIRST}(void) {{}}\nvoid {SECOND}(void) {{}}\n")
        self.definitions = {relative: [FIRST, SECOND]}
        table = {FIRST: ("main", ".text", 0x00100000, len(FIRST_CODE), ".text"),
                 SECOND: ("main", ".text", 0x00100040, len(SECOND_CODE), ".text")}
        self.tables = {version: {} for version in ["us", "pal"]}
        self.tables[native] = table
        self.discs[native] = {table[FIRST][:4]: FIRST_CODE, table[SECOND][:4]: SECOND_CODE}
        obj = Path(match_map.object_of(relative))
        obj.parent.mkdir(parents=True, exist_ok=True)
        if object_present:
            obj.write_bytes(grouped_object(second))
        elif obj.exists():
            obj.unlink()
        self.map_path = self.root / "config" / levels.V / "map.tsv"
        self.map_path.write_bytes(UNRELATED)
        return relative

    def update(self, sources=None):
        with redirect_stdout(io.StringIO()):
            match_map.update_native(sources or [str(self.source)])

    def test_us_and_pal_grouped_native_sources_preserve_unrelated_bytes(self):
        for native in ["us", "pal"]:
            with self.subTest(native=native):
                relative = self.prepare(native)
                previous = match_map.serialize_row((FIRST, relative, "nomatch", "-", "-", 0.0)).replace(b"\n", b"\r\n")
                self.map_path.write_bytes(UNRELATED + previous)
                self.map_path.chmod(0o640)
                previous_mode = stat.S_IMODE(self.map_path.stat().st_mode)
                self.update()
                self.assertEqual(stat.S_IMODE(self.map_path.stat().st_mode), previous_mode)
                payload = self.map_path.read_bytes()
                self.assertTrue(payload.startswith(UNRELATED))
                rows = {row["name"]: row for row in match_map.read_map(self.map_path)}
                for name in [FIRST, SECOND]:
                    self.assertEqual(rows[name]["status"], "match")
                    self.assertEqual(rows[name]["file"], relative)
                    self.assertEqual(rows[name]["places"], [self.tables[native][name][:4]])

    def test_pal_on_us_needs_no_object_or_disc_bytes(self):
        self.prepare("pal", active="us", object_present=False)
        with patch.object(match_map, "compiled", side_effect=AssertionError("object read")), \
                patch.object(check_func, "disc_bytes", side_effect=AssertionError("disc read")):
            self.update()
        rows = {row["name"]: row for row in match_map.read_map(self.map_path)}
        self.assertEqual([rows[name]["status"] for name in [FIRST, SECOND]], ["other", "other"])
        self.assertEqual(levels.V, "us")
        self.assertTrue(self.map_path.read_bytes().startswith(UNRELATED))

    def test_unrelocated_mutation_aborts_the_whole_update(self):
        changed = struct.pack("<I", 0x24820003) + SECOND_CODE[4:]
        self.prepare(second=changed)
        with self.assertRaisesRegex(ValueError, "bytes or object definition differ"):
            self.update()
        self.assertEqual(self.map_path.read_bytes(), UNRELATED)

    def test_invalid_admissions_preserve_the_baseline(self):
        cases = ["collision", "duplicate", "removed", "moved", "catalogue", "object", "alias", "outside"]
        for case in cases:
            with self.subTest(case=case):
                relative = self.prepare("us" if case == "alias" else "pal", active="pal",
                                        object_present=case != "object")
                sources = None
                if case == "collision":
                    self.definitions["src/game/collision.c"] = [FIRST]
                    collision = self.root / "src/game/collision.c"
                    collision.parent.mkdir(parents=True, exist_ok=True)
                    collision.write_text(f"void {FIRST}(void) {{}}\n")
                elif case == "duplicate":
                    self.definitions[relative].append(FIRST)
                    with self.source.open("a") as source:
                        source.write(f"void {FIRST}(void) {{}}\n")
                elif case == "removed":
                    self.definitions[relative].remove(SECOND)
                    self.source.write_text(f"void {FIRST}(void) {{}}\n")
                    self.map_path.write_bytes(UNRELATED + match_map.serialize_row(
                        (SECOND, relative, "match", SECOND, "main:.text:00100040:16", 100.0)))
                elif case == "moved":
                    self.map_path.write_bytes(UNRELATED + match_map.serialize_row(
                        (FIRST, "src/pal/game/old.c", "match", FIRST, "main:.text:00100000:12", 100.0)))
                elif case == "catalogue":
                    del self.tables["pal"][SECOND]
                elif case == "outside":
                    outside = self.root / "outside.c"
                    outside.write_text(f"void {FIRST}(void) {{}}\n")
                    sources = [str(outside)]
                before = self.map_path.read_bytes()
                with self.assertRaises(ValueError):
                    self.update(sources)
                self.assertEqual(self.map_path.read_bytes(), before)

    def test_cli_write_is_exclusive_but_check_can_follow_update(self):
        with patch.object(sys, "argv", ["match_map.py", "--write", "--update-native", "source.c"]), \
                redirect_stderr(io.StringIO()), self.assertRaises(SystemExit) as error:
            match_map.main()
        self.assertEqual(error.exception.code, 2)
        with patch.object(sys, "argv", ["match_map.py", "--update-native", "source.c", "--check"]), \
                patch.object(match_map, "update_native") as update, patch.object(match_map, "check", return_value=0) as check, \
                self.assertRaises(SystemExit) as error:
            match_map.main()
        self.assertEqual(error.exception.code, 0)
        update.assert_called_once_with(["source.c"])
        check.assert_called_once_with()


if __name__ == "__main__":
    unittest.main(verbosity=2)
