/* Not matching yet: SIZE ours 48 / retail 56 (tools/try_func.py func_01EA9888 --diff). Not part of the build. */
/* Store a 32-bit value into four bytes, least significant first, and report 0. */
s32 func_01EA9888(u8 *arg0, u32 arg1) {
    u32 byte1 = arg1 >> 8;
    u32 byte3 = arg1 >> 24;
    u32 byte2 = arg1 >> 16;

    if (arg0 == 0) {
        return 2;
    }
    arg0[0] = arg1;
    arg0[1] = byte1;
    arg0[2] = byte2;
    arg0[3] = byte3;
    return 0;
}
