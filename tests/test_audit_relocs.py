"""Relocation checks use synthetic ELF objects, without a game dump or toolchain."""
import io
import struct
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import audit_relocs as audit
import retail
from elftools.elf.elffile import ELFFile


def object_bytes(code, target='', literal=None, relocation=4, offsets=(0,)):
    """A minimal MIPS ELF32 relocatable containing one function and relocation."""
    function = 'func_L01_00110000' if target else 'func_00110000'
    strings = b'\0' + function.encode() + b'\0' + target.encode() + b'\0'
    target_offset = len(function) + 2 if target else 0
    symbol = lambda name, value, size, info, section: struct.pack('<IIIBBH', name, value, size, info, 0, section)
    symbols = (bytes(16) + symbol(1, 0, len(code), 0x12, 1)
               + symbol(target_offset, 0, 0, 0x10 if target else 3, 0 if target else 2))
    names = ['.text', '.lit4', '.rel.text', '.symtab', '.strtab', '.shstrtab', '.reginfo']
    name_table = b'\0' + b''.join(n.encode() + b'\0' for n in names)
    name_offsets = {n: name_table.index(n.encode() + b'\0') for n in names}
    # type, flags, data, link, info, alignment, entry size
    sections = [(1, 6, code, 0, 0, 4, 0), (1, 2, literal or b'', 0, 0, 4, 0),
                (9, 0, b''.join(struct.pack('<II', off, (2 << 8) | relocation) for off in offsets), 4, 1, 4, 8),
                (2, 0, symbols, 5, 1, 4, 16), (3, 0, strings, 0, 0, 1, 0),
                (3, 0, name_table, 0, 0, 1, 0),
                (0x70000006, 0, struct.pack('<6I', 0, 0, 0, 0, 0, 0x4000), 0, 0, 4, 0)]
    body = bytearray(52)
    headers = [bytes(40)]
    for name, (typ, flags, data, link, info, alignment, entry_size) in zip(names, sections):
        body.extend(bytes((-len(body)) % alignment))
        offset = len(body)
        body.extend(data)
        headers.append(struct.pack('<10I', name_offsets[name], typ, flags, 0, offset,
                                   len(data), link, info, alignment, entry_size))
    body.extend(bytes((-len(body)) % 4))
    header_offset = len(body)
    body.extend(b''.join(headers))
    body[:52] = struct.pack('<16sHHIIIIIHHHHHH', b'\x7fELF\x01\x01\x01' + bytes(9),
                            1, 8, 1, 0, 0, header_offset, 0, 52, 0, 0, 40, 8, 6)
    return function, bytes(body)


def checker(sections, overlay=False):
    # Supply an in-memory retail fixture instead of loading proprietary dumps.
    c = audit.Checker.__new__(audit.Checker)
    c.sizes = {} if overlay else {'func_00110000': (0x110000, 8)}
    c.ovl = {'func_L01_00110000': ('L01', 0x110000, 8)} if overlay else {}
    c.ovl_secs = {'L01': sections} if overlay else {}
    c.secs, c.alias, c.lib_syms = sections, {}, {}
    c.main_copies = {('func_00400000', 'L01'): 0x500000}
    c.checked, c.mismatches, c.unresolved = 0, [], []
    c.by_code, c.digests = {'unique': 0, 'twin': 0, 'catalogue': 0}, {}
    return c


class RelocationTests(unittest.TestCase):
    def check(self, c, function, obj, expected_checks=1):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / 'fixture.o'
            path.write_bytes(obj)
            c.check_object(str(path), {function}, set())
        self.assertEqual(c.checked, expected_checks)
        return c

    def call(self, target):
        function, obj = object_bytes(struct.pack('<II', 0x0C000000, 0), 'func_00400000')
        retail = struct.pack('<II', 0x0C000000 | (target >> 2), 0)
        return self.check(checker([(0x110000, 8, '.text', retail)], True), function, obj)

    def test_named_main_copy_is_accepted_in_its_catalogued_level(self):
        c = self.call(0x500000)
        self.assertEqual(c.mismatches, [])
        self.assertEqual(c.unresolved, [])

    def test_neighbour_of_named_main_copy_is_rejected(self):
        c = self.call(0x500004)
        self.assertEqual(len(c.mismatches), 1)

    def test_catalogued_call_does_not_accept_a_data_symbol_or_another_level(self):
        c = checker([], True)
        self.assertIsNone(c.same_code('D_00400000', 'L01', 0x500000))
        self.assertIsNone(c.same_code('func_00400000', 'L02', 0x500000))

    def literal(self, retail_value, opcode=0x31):
        compiled = struct.pack('<II', (opcode << 26) | (28 << 21) | (12 << 16) | 0xC000, 0)
        function, obj = object_bytes(compiled, literal=struct.pack('<f', 0.5), relocation=8)
        retail = struct.pack('<II', (opcode << 26) | (28 << 21) | (12 << 16)
                             | ((0x220000 - audit.GP) & 0xFFFF), 0)
        secs = [(0x110000, 8, '.text', retail), (0x220000, 4, '.lit4', struct.pack('<f', retail_value))]
        return self.check(checker(secs), function, obj)

    def test_literal_relocation_checks_the_value_at_the_retail_gp_address(self):
        c = self.literal(0.5)
        self.assertEqual(c.mismatches, [])
        self.assertEqual(c.unresolved, [])

    def test_wrong_literal_value_is_rejected(self):
        c = self.literal(0.75)
        self.assertEqual(len(c.mismatches), 1)

    def test_unsupported_literal_instruction_stays_unresolved(self):
        c = self.literal(0.5, opcode=0)
        self.assertEqual(len(c.unresolved), 1)

    def test_literal_mask_keeps_the_destination_register_and_opcode(self):
        code = struct.pack('<II', 0xC78CC000, 0)
        _, obj = object_bytes(code, literal=struct.pack('<f', 0.5), relocation=8)
        masks = retail.reloc_masks(ELFFile(io.BytesIO(obj)))
        moved = struct.pack('<II', 0xC78DC000, 0)
        self.assertNotEqual(retail.fields(code, masks), retail.fields(moved, masks))
        other_opcode = struct.pack('<II', 0xD78CC000, 0)
        self.assertNotEqual(retail.fields(code, masks), retail.fields(other_opcode, masks))
        relocated = struct.pack('<II', 0xC78CA681, 0)
        self.assertEqual(retail.fields(code, masks), retail.fields(relocated, masks))

    def test_literal_can_use_a_nonzero_pool_offset(self):
        code = struct.pack('<II', 0xC78CC004, 0)
        pool = struct.pack('<ff', 0.5, 0.75)
        function, obj = object_bytes(code, literal=pool, relocation=8)
        want = struct.pack('<II', 0xC78CA685, 0)
        c = checker([(0x110000, 8, '.text', want), (0x220000, 8, '.lit4', pool)])
        self.check(c, function, obj)
        self.assertEqual(c.unresolved, [])
        self.assertEqual(c.mismatches, [])

    def test_all_literal_references_must_agree_on_the_pool_base(self):
        code = struct.pack('<4I', 0xC78CC000, 0xC78DC004, 0x03E00008, 0)
        pool = struct.pack('<ff', 0.5, 0.75)
        function, obj = object_bytes(code, literal=pool, relocation=8, offsets=(0, 4))
        # Both values are correct, but the second reference has an extra 4-byte gap.
        want = struct.pack('<4I', 0xC78CA681, 0xC78DA689, 0x03E00008, 0)
        placed = struct.pack('<fff', 0.5, 0.0, 0.75)
        c = checker([(0x110000, 16, '.text', want), (0x220000, 12, '.lit4', placed)])
        c.sizes['func_00110000'] = (0x110000, 16)
        self.check(c, function, obj, expected_checks=2)
        self.assertEqual(c.unresolved, [])
        self.assertEqual(len(c.mismatches), 1)

    def test_literal_load_can_check_eight_bytes(self):
        code = struct.pack('<II', 0xD78CC000, 0)
        pool = struct.pack('<d', 3.125)
        function, obj = object_bytes(code, literal=pool, relocation=8)
        want = struct.pack('<II', 0xD78CA681, 0)
        c = checker([(0x110000, 8, '.text', want), (0x220000, 8, '.lit8', pool)])
        self.check(c, function, obj)
        self.assertEqual(c.unresolved, [])
        self.assertEqual(c.mismatches, [])

    def test_unmatched_library_callee_does_not_become_a_counted_match(self):
        _, _, _, aliases, symbols = audit.load_tables()
        function, obj = object_bytes(struct.pack('<II', 0x0C000000, 0), '__udivdi3')
        retail = struct.pack('<II', 0x0C000000 | (0x12FEB0 >> 2), 0)
        c = checker([(0x110000, 8, '.text', retail)], True)
        c.lib_syms = symbols
        self.check(c, function, obj)
        self.assertEqual(c.unresolved, [])
        self.assertEqual(c.mismatches, [])
        self.assertNotIn('__udivdi3', {symbol for _, symbol in aliases})


if __name__ == '__main__':
    unittest.main()
