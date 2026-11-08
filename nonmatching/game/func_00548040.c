/* Not matching yet: SIZE ours 52 / retail 56 (tools/try_func.py func_00548040 --diff). Not part of the build. */
/* Store arg2 in the word of slot arg1, clamped to 0..0x1F. */
void func_00548040(void *arg0, s32 arg1, s32 arg2) {
    if (arg1 >= 0x20) {
        arg1 = 0x1F;
    }
    if (arg1 < 0) {
        arg1 = 0;
    }
    if (arg2 < 0) {
        arg2 = 0;
    }
    (*(s32 *)((u8 *)arg0 + arg1 * 0x44 + 0xA34)) = arg2;
}
