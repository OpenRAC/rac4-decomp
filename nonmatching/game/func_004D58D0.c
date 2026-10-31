/* Not matching yet: BYTES 2/124 (tools/try_func.py func_004D58D0 --diff). Not part of the build. */
extern void func_004A1310(void *arg0, s32 arg1);
extern void func_004A1358(void *arg0, s32 arg1);
extern void func_004E0858(void);
extern s32 func_004E21D8(u32 index, s32 param_a, s32 param_b);
extern u8 D_31B9B8[];
extern u8 D_31CCC4[];

// Sets bit 1 of the word at D_31B9B8+4 when the word at D_31CCC4+0x50 is at least 2, after one of two helpers.
void func_004D58D0(s32 arg0) {
    u8 *base;
    u32 *flags;

    base = D_31CCC4;
    if (*(s32 *)(base + 0x50) >= 2) {
        if (arg0 != 0) {
            func_004A1358(base, arg0);
        } else {
            func_004A1310(base, arg0);
        }
        flags = (u32 *)D_31B9B8;
        flags[1] = flags[1] | 2;
        func_004E21D8(0, 0, 0);
        func_004E0858();
    }
}
