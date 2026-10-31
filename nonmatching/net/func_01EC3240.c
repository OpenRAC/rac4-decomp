/* Not matching yet: BYTES 8/72 (tools/try_func.py func_01EC3240 --diff). Not part of the build. */
extern s32 func_001268A0(int n, int id);

/* Adds the callee's positive result into *arg2 when arg1 is non-negative; returns 0. */
s32 func_01EC3240(s32 arg0, s32 arg1, s32 *arg2) {
    s32 temp;

    if (arg1 >= 0) {
        temp = func_001268A0(arg0, arg1);
        if (temp > 0) {
            *arg2 += temp;
        }
    }
    return 0;
}
