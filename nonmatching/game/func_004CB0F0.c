/* Not matching yet: BYTES 10/88 (tools/try_func.py func_004CB0F0 --diff). Not part of the build. */
/* When arg0 is nonzero, stores a word from the D_00171948 entry selected by D_30E9DC into D_0021FA2C and calls func_004CA1D0(2, 0); otherwise calls func_004CA1D0(1, 0). */
extern void func_004CA1D0(int arg0, int arg1);
extern u8 D_00171948[];
extern s32 D_30E9DC[];
extern s32 D_0021FA2C;

void func_004CB0F0(s32 arg0) {
    s32 temp_a2;
    u8 *p;

    if (arg0 != 0) {
        temp_a2 = D_30E9DC[0] << 5;
        p = (u8 *)D_00171948 + temp_a2;
        D_0021FA2C = *(s32 *)(p + 0x4C);
        func_004CA1D0(2, 0);
        return;
    }
    func_004CA1D0(1, 0);
}
