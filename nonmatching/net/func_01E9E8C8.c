/* Not matching yet: BYTES 9/80 (tools/try_func.py func_01E9E8C8 --diff). Not part of the build. */
extern s32 func_01EA3F58(s32);
extern s32 func_01EA42D8(s32);
extern s32 func_01EA57B8();
extern s32 func_01EA57F8();

/* Returns the first nonzero of two checks; when the first is zero, the second pair picks the result (helper result when the second check is zero). */
s32 func_01E9E8C8(s32 arg0) {
    s32 r;
    s32 a;
    s32 b;

    r = func_01EA42D8(func_01EA57B8());
    if (r == 0) {
        a = func_01EA3F58(arg0);
        b = func_01EA42D8(func_01EA57F8());
        r = (b == 0) ? a : b;
    }
    return r;
}
