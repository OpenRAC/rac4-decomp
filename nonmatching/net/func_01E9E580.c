/* Not matching yet: BYTES 9/80 (tools/try_func.py func_01E9E580 --diff). Not part of the build. */
extern s32 func_01EA0728(s32);
extern s32 func_01EA42D8(s32);
extern s32 func_01EA57B8();
extern s32 func_01EA57F8();

// Returns func_01EA42D8 of func_01EA57B8() if nonzero; otherwise func_01EA0728 of arg0, unless func_01EA42D8 of func_01EA57F8() is nonzero, which is returned.
s32 func_01E9E580(s32 arg0) {
    s32 temp_s0;
    s32 temp_v0;
    s32 var_v0;

    var_v0 = func_01EA42D8(func_01EA57B8());
    if (var_v0 == 0) {
        temp_s0 = func_01EA0728(arg0);
        temp_v0 = func_01EA42D8(func_01EA57F8());
        var_v0 = (temp_v0 == 0) ? temp_s0 : temp_v0;
    }
    return var_v0;
}
