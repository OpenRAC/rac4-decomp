/* Not matching yet: SIZE ours 72 / retail 92 (tools/try_func.py func_01EB2C50 --diff). Not part of the build. */
void func_01EB2C50(u8 *arg0, u8 *arg1, s32 arg2) {
    do {
        s32 i;

        for (i = 0; i < 8; i++) {
            arg0[i] = arg1[i];
        }
        arg2 -= 8;
        arg1 += 8;
        arg0 += 8;
    } while (arg2 > 0);
}
