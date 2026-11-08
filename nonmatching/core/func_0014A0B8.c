/* Not matching yet: BYTES 39/108 (tools/try_func.py func_0014A0B8 --diff). Not part of the build. */
extern f32 D_001A1950;

/* Index of the point nearest the reference in the squared-distance search. */
s32 func_0014A0B8(f32 *arg0, f32 *arg1, s32 arg2) {
    f32 best = D_001A1950;
    f32 *p = arg1;
    s32 result = 0;
    s32 i;

    for (i = 0; i < arg2; i++) {
        f32 dx = p[0] - arg0[0];
        f32 dy = p[1] - arg0[1];
        f32 distance = dx * dx + dy * dy;

        if (distance < best) {
            best = distance;
            result = i;
        }
        p++;
    }
    return result;
}
