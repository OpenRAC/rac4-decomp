/* Not matching yet: SIZE ours 52 / retail 56 (tools/try_func.py func_00547DC8 --diff). Not part of the build. */
/* Store arg2 in the halfword of slot arg1, clamped to 0..0x1F. */
void func_00547DC8(void *arg0, s32 arg1, s32 arg2) {
    void *self = arg0;

    if (arg1 >= 0x20) {
        arg1 = 0x1F;
    }
    if (arg1 < 0) {
        arg1 = 0;
    }
    if (arg2 < 0) {
        arg2 = 0;
    }
    (*(s16 *)((u8 *)self + arg1 * 0x44 + 0xA32)) = arg2;
}
