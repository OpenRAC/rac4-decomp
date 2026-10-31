/* Not matching yet: BYTES 3/112 (tools/try_func.py func_00500F00 --diff). Not part of the build. */
extern s32 D_0021DDCC;
extern void func_004FFEE0(s32 arg0);
extern s32 func_005005D8(s32 *arg0);
extern void func_00503B58(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_00503D78(s32 arg0, void *arg1);

/* Calls func_004FFEE0 on the entry at index p[5] of arg0[1]; when the flag at 0x1C4 of D_0021DDCC is set, first passes a local buffer to func_00503B58 and func_00503D78. */
void func_00500F00(s32 *arg0) {
    s32 buf[2];
    s32 s0;
    s32 *p;

    p = (s32 *)arg0[1];
    s0 = *(s32 *)((u32)p + (p[5] << 2));
    if (s0 != 0) {
        if (*(s32 *)((u32)D_0021DDCC + 0x1C4) != 0) {
            func_00503B58(buf, 0, 1, 0x10000);
            func_00503D78(func_005005D8(s0), buf);
        }
        func_004FFEE0(s0);
    }
}
