"""The landing gate rejects inline assembly even when GCC uses __volatile__."""

import unittest

import wave


class PlainCPolicyTests(unittest.TestCase):
    def test_inline_asm_volatile_barrier_is_rejected(self):
        self.assertEqual(
            wave.banned('    __asm__ __volatile__("" : "+r"(value));'),
            "inline assembly",
        )

    def test_plain_symbol_declaration_is_allowed(self):
        self.assertIsNone(wave.banned('extern u8 D_0016FD20[];'))


if __name__ == "__main__":
    unittest.main()
