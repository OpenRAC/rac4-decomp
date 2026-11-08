/* Not matching yet: BYTES 18/44 (tools/try_func.py func_00547E00 --diff). Not part of the build. */
/* Signed halfword of slot arg1, clamped to 0..0x1F. */
s16 func_00547E00(void *arg0, s32 arg1) {
    s32 index = arg1;

    if (index >= 0x20) {
        index = 0x1F;
    }
    if (index < 0) {
        index = 0;
    }
    return (*(s16 *)((u8 *)arg0 + index * 0x44 + 0xA32));
}
