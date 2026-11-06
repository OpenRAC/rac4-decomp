"""Assembler-fixup regressions using small, synthetic MIPS objects."""

from contextlib import redirect_stdout
import io
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

from elf_test_objects import ElfSection, ElfSymbol, elf_bytes
import ps2eeas_nops as nops


def words(*values):
    return struct.pack("<" + "I" * len(values), *values)


LOOP = words(
    0x0C000000,  # jal external; its following nop is a delay slot, not padding
    0,
    0x1480FFFD,  # bne $4, $zero, start
    0,
    0x03E00008,  # jr $ra
    0,
)
FP = words(
    0x46020032,  # c.eq.s $f0, $f2
    0x45010001,  # bc1t after_delay
    0,
    0x03E00008,
    0,
)

SOURCE = """\t.text
\t.ent func_00100000
func_00100000:
\t.set noreorder
$Lloop:
\tjal external
\tnop
\tbne $4,$zero,$Lloop
\tnop
\tjr $ra
\tnop
\t.end func_00100000
\t.section .text.func_00200000
\t.ent func_00200000
func_00200000:
\t.set reorder
\tc.eq.s $f0,$f2
\tbc1t $Lafter
\tnop
$Lafter:
\tjr $ra
\tnop
\t.end func_00200000
"""


class FunctionSectionTests(unittest.TestCase):
    def transform(self, source, sections, symbols):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            src, obj, dst = root / "input.s", root / "input.o", root / "output.s"
            src.write_text(source)
            indices = {name: i for i, (name, _) in enumerate(sections, 1)}
            obj.write_bytes(elf_bytes(
                [ElfSection(name, data) for name, data in sections],
                [ElfSymbol(name, indices[section], start, size)
                 for name, section, start, size in symbols],
            ))
            output = io.StringIO()
            arguments = ["ps2eeas_nops.py", str(src), str(obj), str(dst)]
            with patch.object(sys, "argv", arguments), redirect_stdout(output):
                nops.main()
            return dst.read_text(), output.getvalue()

    def test_same_offsets_in_distinct_sections_keep_hazards_separate(self):
        transformed, log = self.transform(
            SOURCE,
            [(".text", b""), (".text.func_00100000", LOOP), (".text.func_00200000", FP)],
            [("func_00100000", ".text.func_00100000", 0, len(LOOP)),
             ("func_00200000", ".text.func_00200000", 0, len(FP))],
        )
        self.assertIn("\tjal external\n\tnop\n\tnop\n\tnop\n\tbne", transformed)
        self.assertIn("\tc.eq.s $f0,$f2\n\t.set\tnoreorder\n\tnop\n\t.set\treorder\n\tbc1t", transformed)
        self.assertIn("padded 1 short loop(s), 1 FP compare(s)", log)

    def test_ordinary_text_and_function_sections_produce_identical_edits(self):
        separate, _ = self.transform(
            SOURCE,
            [(".text.func_00100000", LOOP), (".text.func_00200000", FP)],
            [("func_00100000", ".text.func_00100000", 0, len(LOOP)),
             ("func_00200000", ".text.func_00200000", 0, len(FP))],
        )
        ordinary, _ = self.transform(
            SOURCE,
            [(".text", bytes(8) + LOOP + FP)],
            [("func_00100000", ".text", 8, len(LOOP)),
             ("func_00200000", ".text", 8 + len(LOOP), len(FP))],
        )
        self.assertEqual(ordinary, separate)

    def test_source_object_event_mismatch_still_rejects(self):
        with self.assertRaisesRegex(SystemExit, "func_00100000.*refusing to guess"):
            self.transform(
                SOURCE.replace("\tbne $4,$zero,$Lloop\n", ""),
                [(".text.func_00100000", LOOP), (".text.func_00200000", FP)],
                [("func_00100000", ".text.func_00100000", 0, len(LOOP)),
                 ("func_00200000", ".text.func_00200000", 0, len(FP))],
            )

    def test_local_labels_do_not_carry_between_functions(self):
        source = SOURCE.split("\t.section", 1)[0] + """\t.section .text.func_00200000
\t.ent func_00200000
func_00200000:
\t.set noreorder
\tjal external
\tnop
\tbne $4,$zero,$Lloop
\tnop
\tjr $ra
\tnop
\t.end func_00200000
"""
        with self.assertRaisesRegex(SystemExit, "func_00200000.*refusing to guess"):
            self.transform(
                source,
                [(".text.func_00100000", LOOP), (".text.func_00200000", LOOP)],
                [("func_00100000", ".text.func_00100000", 0, len(LOOP)),
                 ("func_00200000", ".text.func_00200000", 0, len(LOOP))],
            )

    def test_mtc1_hazard_is_fixed_in_owning_function_section(self):
        source = """\t.ent func_00300000
func_00300000:
\t.set reorder
\tmtc1 $4,$f0
\tadd.s $f2,$f0,$f4
\tjr $ra
\tnop
\t.end func_00300000
"""
        code = words(0x44840000, 0x46040080, 0x03E00008, 0)
        transformed, log = self.transform(
            source, [(".text.func_00300000", code)],
            [("func_00300000", ".text.func_00300000", 0, len(code))],
        )
        self.assertIn("\tmtc1 $4,$f0\n\t.set\tnoreorder\n\tnop\n\t.set\treorder\n\tadd.s", transformed)
        self.assertIn("0 FP compare(s), 1 mtc1 use(s)", log)

    def test_zero_sized_function_is_ignored(self):
        source = "\t.ent func_00300000\nfunc_00300000:\n\t.end func_00300000\n"
        transformed, log = self.transform(source, [(".text.empty", b"")],
                                          [("func_00300000", ".text.empty", 0, 0)])
        self.assertEqual(transformed, source)
        self.assertIn("padded 0 short loop(s), 0 FP compare(s), 0 mtc1 use(s)", log)


if __name__ == "__main__":
    unittest.main()
