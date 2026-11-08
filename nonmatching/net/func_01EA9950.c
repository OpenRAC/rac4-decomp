/* Not matching yet: SIZE ours 56 / retail 52 (tools/try_func.py func_01EA9950 --diff). Not part of the build. */
/* Read two bytes as a big-endian halfword into the buffer, or report 2. */
s32 func_01EA9950(u8 *arg0, u16 *arg1) {
    u16 value;

    if (arg0 == 0 || arg1 == 0) {
        return 2;
    }
    value = arg0[0] << 8;
    *arg1 = value;
    value |= arg0[1];
    *arg1 = value;
    return 0;
}
