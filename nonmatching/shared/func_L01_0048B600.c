/* Not matching yet: BYTES 21/72 (tools/try_func.py func_L01_0048B600 --diff). Not part of the build. */
extern f32 func_L01_005D63B0(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4);

void func_L01_0048B600(u8 *arg0, u8 *arg1, f32 fparg0) {
    if ((*(u8 *)(arg0 + 0x20) != 4) || (*(u8 *)(arg1 + 0x168) == 0)) {
        func_L01_005D63B0(*(s32 *)(arg1 + 0x1B0), 1, *(f32 *)(arg1 + 0xDAC), *(f32 *)(arg1 + 0x1B4), fparg0);
    }
}
