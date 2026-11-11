"""Proven C boundaries must not promote alignment padding to function code."""
import struct
import unittest

import inventory


class ProvenBoundaryTests(unittest.TestCase):
    def section(self, words, pointers=()):
        return inventory.Section('main', 'core.text', 0x1000,
                                 struct.pack('<%dI' % len(words), *words),
                                 [list(pointers)] if pointers else [])

    def test_padding_before_dead_stack_restore_stays_outside_function(self):
        words = [0x24020001, inventory.JR_RA, 0, 0,
                 0x27BD0050, 0, 0x27BDFFB0, inventory.JR_RA, 0]
        rows = self.section(words).entries(proven={0x1000: 0x100C})
        self.assertEqual(rows, [(0x1000, 12, 'function'),
                                (0x1010, 4, 'remnant'),
                                (0x1018, 12, 'function')])

    def test_adjacent_proven_entry_at_nop_is_preserved(self):
        words = [0x24020001, inventory.JR_RA, 0,
                 0, 0x24020002, inventory.JR_RA, 0]
        rows = self.section(words, [0x100C]).entries(proven={0x1000: 0x100C,
                                                         0x100C: 0x101C})
        self.assertEqual(rows, [(0x1000, 12, 'function'),
                                (0x100C, 16, 'function')])


if __name__ == '__main__':
    unittest.main()
