/* Not matching yet: BYTES 8/88 (tools/try_func.py func_01EC92E8 --diff). Not part of the build. */
extern void func_01ECCEC8(void);
extern void *D_00167F38_[];
#define D_00167F38 (D_00167F38_[0])

// Calls func_01ECCEC8, then copies five words from arg0 into the object D_00167F38 points to, returning 0.
s32 func_01EC92E8(s32 *arg0) {
    u8 *p;

    func_01ECCEC8();
    p = D_00167F38;
    *(s32 *)(p + 0xF8) = arg0[0];
    *(s32 *)(p + 0xFC) = arg0[1];
    *(s32 *)(p + 0x100) = arg0[2];
    *(s32 *)(p + 0x108) = arg0[3];
    *(s32 *)(p + 0x10C) = arg0[4];
    return 0;
}
