/* Not matching yet: BYTES 2/24 (tools/try_func.py func_L00_004F1738 --diff). Not part of the build. */
/* cflags: -fno-schedule-insns -fno-schedule-insns2 */
u32 func_L00_004F1738(u32 value) {
    u32 r = (value << 8) & 0xFF00;
    value = (value >> 8) & 0xFF;
    return r | value;
}
