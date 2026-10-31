/* Not matching yet: BYTES 14/100 (tools/try_func.py func_0049E5B0 --diff). Not part of the build. */
extern void func_0049C158(s32 param_a, s32 param_b, s32 source, s32 mode);
extern void func_00505328(s32, s32);
// Calls func_0049C158 with mode 3 for the slot at arg0 and arg1, then func_00505328 with 0x80D0D0D0 at the next offset.
void func_0049E5B0(s32 arg0, s32 arg1) {
    s32 s0;
    s32 s1;

    s0 = arg1 * 2;
    s1 = arg0 << 6;
    func_0049C158(arg0, 3, s1 + (s0 + 0x130005), 0);
    func_00505328(s1 + (s0 + 0x130006), 0x80D0D0D0);
}
