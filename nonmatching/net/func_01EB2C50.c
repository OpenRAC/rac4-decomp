/* Not matching yet: SIZE ours 128 / retail 92 (tools/try_func.py func_01EB2C50 --diff). Not part of the build. */
/* Copy eight-byte blocks out as bytes, least significant first. */
void func_01EB2C50(u8 *arg0, u64 *arg1, s32 arg2) {
    u64 value;

    do {
        value = *arg1;
        arg0[0] = value;
        value >>= 8;
        arg0[1] = value;
        value >>= 8;
        arg0[2] = value;
        value >>= 8;
        arg0[3] = value;
        value >>= 8;
        arg0[4] = value;
        value >>= 8;
        arg0[5] = value;
        value >>= 8;
        arg0[6] = value;
        value >>= 8;
        arg0[7] = value;
        arg2 -= 8;
        arg1++;
        arg0 += 8;
    } while (arg2 > 0);
}
