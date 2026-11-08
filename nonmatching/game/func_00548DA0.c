/* Not matching yet: BYTES 19/52 (tools/try_func.py func_00548DA0 --diff). Not part of the build. */
/* Bit 7 of the byte 0xA30 of slot arg1, clamped to 0..0x1F. */
s32 func_00548DA0(void *arg0, s32 arg1) {
    if (arg1 >= 0x20) {
        arg1 = 0x1F;
    }
    if (arg1 < 0) {
        arg1 = 0;
    }
    return (u64)((*(u8 *)((u8 *)arg0 + arg1 * 0x44 + 0xA30)) ^ 0x80) >> 7;
}
