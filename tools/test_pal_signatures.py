"""Regression cases for prototypes that the signature checker must see."""
import unittest

from check_pal_signatures import parse_declarations


class PrototypeTests(unittest.TestCase):
    def test_external_linkage_without_extern(self):
        self.assertEqual(
            list(parse_declarations("void func_00453F30(s32, s32, s32);")),
            [("func_00453F30", "void", "s32,s32,s32")],
        )

    def test_pointer_result_without_space_after_star(self):
        self.assertEqual(
            list(parse_declarations("extern const char *func_0045E850(s32);")),
            [("func_0045E850", "char*", "s32")],
        )

    def test_parameter_names_are_not_types(self):
        self.assertEqual(
            list(parse_declarations("void func_00453F30(void *output, const void *input, u32 size);")),
            [("func_00453F30", "void", "void*,void*,u32")],
        )

    def test_multiline_and_shared_return_type(self):
        self.assertEqual(
            list(parse_declarations("extern s32 func_004A2798(\nconst s32 *, s32),\nfunc_004A0728(s32);")),
            [("func_004A2798", "s32", "s32*,s32"), ("func_004A0728", "s32", "s32")],
        )

    def test_comments_calls_and_definitions_are_not_prototypes(self):
        self.assertEqual(
            list(parse_declarations("""
/* extern s32 func_004A0728(s32); */
// void func_00453F30(s32, s32, s32);
void func_004AECE8(void) {
    func_004A0728(0);
    return func_004A0728(1);
}
""")),
            [],
        )


if __name__ == "__main__":
    unittest.main()
