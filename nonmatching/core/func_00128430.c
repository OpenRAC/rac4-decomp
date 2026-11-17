/* Not matching yet: BYTES 115/144 (tools/try_func.py func_00128430 --diff) (tools/try_func.py func_00128430 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G8 -fno-schedule-insns -fno-schedule-insns2 */
s32 func_00128430(s64 arg0) {
    s64 e;
    u64 x;

    x = arg0;
    e = (u64)(x * 2) >> 0x35;
    e -= 0x433;
    if (e < -0x35) {
        return 0;
    }
    if (e >= 0xD) {
        return 0x270F;
    }
    x = (u64)(x << 0xC) >> 0xC;
    x |= (1ULL << 0x34);
    if (e < 0) {
        e = -e;
        x = x >> (s32)(e - 2);
        if ((x & 3) == 3) {
            x = (x >> 2) + 1;
        } else {
            x = x >> 2;
        }
    } else {
        x = x << (s32)e;
    }
    return x;
}
