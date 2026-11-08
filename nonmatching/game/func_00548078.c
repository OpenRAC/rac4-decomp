/* Not matching yet: BYTES 18/44 (tools/try_func.py func_00548078 --diff). Not part of the build. */
/* Word of slot arg1, clamped to 0..0x1F. */
s32 func_00548078(void *arg0, s32 arg1) {
    if (arg1 >= 0x20) {
        arg1 = 0x1F;
    }
    if (arg1 < 0) {
        arg1 = 0;
    }
    return (*(s32 *)((u8 *)arg0 + arg1 * 0x44 + 0xA34));
}
