/* Not matching yet: BYTES 9/84 (tools/try_func.py func_00147D88 --diff). Not part of the build. */
/* Scans arg0[1..arg1-1] for the largest float (starting from arg0[0]); stores the index of the winner and its value. */
void func_00147D88(f32 *arg0, s32 arg1, s32 *arg2, f32 *arg3) {
    f32 cur;
    f32 best;
    s32 idx;
    s32 i;

    best = arg0[0];
    idx = 0;
    i = 1;
    arg0 += 1;
    if (i < arg1) {
        cur = *arg0;
        do {
            if (best < cur) {
                best = cur;
                idx = i;
            }
            arg0++;
            i++;
            cur = *arg0;
        } while (i < arg1);
    }
    *arg2 = idx;
    *arg3 = best;
}
