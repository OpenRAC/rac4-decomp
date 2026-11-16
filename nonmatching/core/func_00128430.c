/* Not matching yet: BYTES 118/144 (tools/try_func.py func_00128430 --diff) (tools/try_func.py func_00128430 --diff). Not part of the build. */
s64 func_00128430(s64 arg0) {
    s64 e;
    u64 x;

    e = ((u64)(arg0 * 2) >> 0x35) - 0x433;
    if (e < -0x35) {
        return 0;
    }
    if (e >= 0xD) {
        return 0x270F;
    }
    x = ((u64)(arg0 << 0xC) >> 0xC) | (1ULL << 0x34);
    if (e < 0) {
        x = x >> (s32)(((0 - e) - 2));
        if ((x & 3) == 3) {
            x = (x >> 2) + 1;
        } else {
            x = x >> 2;
        }
    } else {
        x = x << (s32)e;
    }
    return (s32)x;
}
