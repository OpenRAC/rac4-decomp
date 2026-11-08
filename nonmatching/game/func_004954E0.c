/* Not matching yet: BYTES 8/48 (tools/try_func.py func_004954E0 --diff). Not part of the build. */
/* Clamp arg1 + arg2 into the range the first word allows. */
s32 func_004954E0(s32 *arg0, s32 arg1, s32 arg2) {
    s32 limit;

    arg1 += arg2;
    if (arg2 < 0) {
        if (arg1 < 0) {
            arg1 = 0;
        }
    } else {
        limit = *arg0 - 1;
        if (limit < arg1) {
            arg1 = limit;
        }
    }
    return arg1;
}
