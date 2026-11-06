"""Behavioral checks for function and relocation ownership in ELF objects."""
from io import BytesIO
import struct
import unittest

from elftools.elf.elffile import ELFFile

from elf_layout import function_layout, functions, section_index
from elf_test_objects import ElfSection, ElfSymbol, elf_bytes
import retail


def elf(sections, symbols, relocations=(), elf_type=1):
    return ELFFile(BytesIO(elf_bytes(sections, symbols, relocations, elf_type)))


class FunctionLayoutTests(unittest.TestCase):
    def test_separate_zero_offset_functions_keep_their_code_and_shared_data(self):
        first = struct.pack("<III", 0x24020011, 0x03E00008, 0)
        second = struct.pack("<II", 0x03E00008, 0x24020022)
        obj = elf(
            [ElfSection(".text", b""), ElfSection(".text.first", first),
             ElfSection(".text.second", second), ElfSection(".sdata", b"\0", flags=3)],
            [ElfSymbol("func_00100000", 2, 0, len(first)),
             ElfSymbol("func_00200000", 3, 0, len(second)),
             ElfSymbol("D_00300000", 4, 0, 1, symbol_type=1),
             ElfSymbol("external_call", 0, 0, 0)],
        )

        found = list(functions(obj))

        self.assertEqual([f.name for f in found], ["func_00100000", "func_00200000"])
        self.assertEqual([f.section_index for f in found], [2, 3])
        self.assertEqual([f.section_name for f in found], [".text.first", ".text.second"])
        self.assertEqual([f.start for f in found], [0, 0])
        self.assertEqual([f.end for f in found], [len(first), len(second)])
        self.assertEqual([f.code for f in found], [first, second])
        self.assertEqual([f.section_data for f in found], [first, second])
        self.assertIsNone(function_layout(obj, obj.get_section_by_name(".symtab").get_symbol(3)))
        self.assertIsNone(function_layout(obj, obj.get_section_by_name(".symtab").get_symbol(4)))

    def test_old_text_functions_keep_nonzero_offsets(self):
        data = b"PAD!" + b"FIRST123" + b"SECOND45" + b"TAIL"
        obj = elf([ElfSection(".text", data)],
                  [ElfSymbol("func_00100000", 1, 4, 8),
                   ElfSymbol("func_00200000", 1, 12, 8)],
                  [(1, [(4, 4, 0), (16, 7, 0)])])

        first, second = list(functions(obj))

        self.assertEqual((first.start, first.end, first.code), (4, 12, b"FIRST123"))
        self.assertEqual((second.start, second.end, second.code), (12, 20, b"SECOND45"))
        self.assertEqual(first.section_index, second.section_index)
        self.assertEqual(retail.reloc_masks(obj), {4: 0x03FFFFFF, 16: 0xFFFF})
        self.assertEqual(retail.reloc_masks(obj), retail.reloc_masks(obj, 1))

    def test_relocatable_symbols_keep_offsets_when_section_has_an_address(self):
        obj = elf([ElfSection(".text", b"FIRST123SECOND45", address=0x1000)],
                  [ElfSymbol("func_00100000", 1, 0, 8),
                   ElfSymbol("func_00200000", 1, 8, 8)])

        first, second = functions(obj)

        self.assertEqual((first.start, first.end, first.code), (0, 8, b"FIRST123"))
        self.assertEqual((second.start, second.end, second.code), (8, 16, b"SECOND45"))

    def test_relocatable_symbol_values_cannot_borrow_the_section_address(self):
        # Treating this offset as a virtual address would wrongly admit the
        # four bytes at offset four. ET_REL values remain section offsets.
        for value, size in [(0x1004, 4), (8, 8)]:
            with self.subTest(value=value, size=size):
                obj = elf([ElfSection(".text", b"HEADbodyTAIL", address=0x1000)],
                          [ElfSymbol("invalid_offset", 1, value, size)])
                with self.assertRaises(ValueError):
                    list(functions(obj))

    def test_executable_and_shared_symbol_addresses_become_section_offsets(self):
        for kind in [2, 3]:  # ET_EXEC and ET_DYN values are virtual addresses.
            with self.subTest(elf_type=kind):
                obj = elf([ElfSection(".text.first", b"HEADbodyTAIL", address=0x1000)],
                          [ElfSymbol("func_00001004", 1, 0x1004, 4)], elf_type=kind)

                found, = functions(obj)

                self.assertEqual((found.start, found.end, found.code), (4, 8, b"body"))

    def test_zero_size_symbol_at_section_end_is_valid_metadata(self):
        obj = elf([ElfSection(".text", b"12345678")],
                  [ElfSymbol("func_00100000", 1, 8, 0)])

        found, = functions(obj)

        self.assertEqual((found.start, found.size, found.end, found.code), (8, 0, 8, b""))

    def test_invalid_function_extents_are_rejected(self):
        cases = [
            ([ElfSection(".text", b"12345678")], ElfSymbol("past_end", 1, 4, 8), 1),
            ([ElfSection(".text", b"12345678")], ElfSymbol("bad_owner", 99, 0, 4), 1),
            ([ElfSection(".text", b"12345678", address=0x1000)],
             ElfSymbol("before_start", 1, 0xFFC, 4), 2),
            ([ElfSection(".text", b"12345678", address=0x1000)],
             ElfSymbol("before_start_shared", 1, 0xFFC, 4), 3),
        ]
        for sections, symbol, kind in cases:
            with self.subTest(function=symbol.name):
                obj = elf(sections, [symbol], elf_type=kind)
                with self.assertRaises(ValueError):
                    list(functions(obj))

    def test_defined_functions_in_non_code_sections_are_rejected(self):
        for section in [ElfSection(".data", b"1234", flags=3),
                        ElfSection(".text", b"1234", flags=6, section_type=8)]:
            with self.subTest(section=section.name, kind=section.section_type):
                obj = elf([section], [ElfSymbol("wrong_owner", 1, 0, 4)])
                with self.assertRaises(ValueError):
                    list(functions(obj))


class RelocationOwnershipTests(unittest.TestCase):
    def test_same_offsets_and_names_do_not_mix_relocations(self):
        first = struct.pack("<II", 0x0C123456, 0x24021111)
        second = struct.pack("<II", 0x3C032222, 0xFFFFFFFF)
        obj = elf(
            [ElfSection(".text", b""), ElfSection(".text.duplicate", first),
             ElfSection(".text.duplicate", second)],
            [ElfSymbol("func_00100000", 2, 0, 8), ElfSymbol("func_00200000", 3, 0, 8)],
            [(2, [(0, 4, 0)]), (3, [(0, 5, 0), (4, 2, 0)])],
        )

        first_view, second_view = functions(obj)
        first_masks = retail.reloc_masks(obj, first_view.section_index)
        second_masks = retail.reloc_masks(obj, second_view.section_index)

        self.assertEqual(first_masks, {0: 0x03FFFFFF})
        self.assertEqual(second_masks, {0: 0xFFFF, 4: 0xFFFFFFFF})
        self.assertEqual(retail.fields(first_view.code, first_masks), (0x0C000000, 0x24021111))
        self.assertEqual(retail.fields(second_view.code, second_masks), (0x3C030000, 0))
        self.assertEqual(retail.reloc_masks(obj), {})
        with self.assertRaises(ValueError):
            retail.reloc_masks(obj, ".text.duplicate")

    def test_section_identity_rejects_invalid_indices_and_preserves_missing_names(self):
        obj = elf([ElfSection(".text", b"")], [])

        self.assertIsNone(section_index(obj, ".missing"))
        self.assertEqual(retail.reloc_masks(obj, ".missing"), {})
        for index in [-1, obj.num_sections()]:
            with self.subTest(index=index):
                with self.assertRaises(ValueError):
                    retail.reloc_masks(obj, index)


if __name__ == "__main__":
    unittest.main()
