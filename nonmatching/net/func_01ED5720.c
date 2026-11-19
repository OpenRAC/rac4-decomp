/* Not matching yet: SIZE ours 88 / retail 84 (tools/try_func.py func_01ED5720 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
extern void func_0011A370(u8 *, u8 *, s32);
extern s32 D_00169D38;
extern u8 D_1B76C0[];
extern u8 D_1B7788[];

void func_01ED5720(u8 *a0) {
    if (D_00169D38 != 0x12) {
        if (D_00169D38 == 0x2D)
            func_0011A370(a0, D_1B76C0, 0xC4);
    } else {
        func_0011A370(a0, D_1B7788, 0xEC);
    }
}
