/* Not matching yet: BYTES 11/76 (tools/try_func.py func_01EA73A8 --diff). Not part of the build. */
/* sets *arg1 from the words of arg0 and returns 0; returns 2 when either pointer is null */
s32 func_01EA73A8(s32 *arg0, s32 *arg1) {
    s32 result = 2;
    s32 nonnull = (arg0 != 0);

    if (arg0 != 0 && arg1 != 0) {
        u32 v1 = arg0[0];

        if (v1 < (u32)arg0[1]) {
            *arg1 = 0;
        } else if (arg0[3] == 0) {
            *arg1 = 0;
        } else if (v1 != 0) {
            *arg1 = nonnull;
        } else {
            *arg1 = 0;
        }
        result = 0;
    }
    return result;
}
