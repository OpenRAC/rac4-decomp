"""Command-line parsing for the automatic structure matcher."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import auto_structs


class AutoStructsArgumentsTests(unittest.TestCase):
    def test_prepare_main_uses_the_main_catalogue(self):
        command, cls, limit = auto_structs.parse_args(["prepare", "main", "120"])
        self.assertEqual((command, cls, limit), ("prepare", "main", 120))

    def test_checker_catalogue_includes_main_and_overlay_functions(self):
        info = auto_structs.check_info()
        self.assertIn("func_0011EB90", info)
        self.assertIn("func_L01_003C7C80", info)

    def test_library_functions_are_not_automatic_candidates(self):
        self.assertFalse(auto_structs.is_game_code("func_00135390"))


if __name__ == "__main__":
    unittest.main()
