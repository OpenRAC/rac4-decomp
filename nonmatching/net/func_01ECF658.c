/* Not matching yet: BYTES 7/92 (tools/try_func.py func_01ECF658 --diff). Not part of the build. */
extern s32 func_01EA42D8(s32);
extern s32 func_01EA9550(void *, u64);
extern s32 D_00167F38_[];
#define D_00167F38 (D_00167F38_[0])
extern s32 D_00169B38_[];
#define D_00169B38 (D_00169B38_[0])
extern s32 D_1B73D8_[];

/* Resets a counter and forwards a computed value through two calls, or returns 8 when the range check fails. */
s32 func_01ECF658(void) {
    u8 *p;

    p = (u8 *)D_00167F38;
    if ((u32)*(s32 *)(p + 0x110) < (u32)*(s32 *)(p + 0xF8)) {
        D_00169B38 = 0;
        return func_01EA42D8(func_01EA9550(D_1B73D8_, (u64)(u32)(*(s32 *)(p + 0xFC) * 4)));
    }
    return 8;
}
