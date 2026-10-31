/* Not matching yet: BYTES 9/80 (tools/try_func.py func_01E9E7E8 --diff). Not part of the build. */
extern s32 func_01EA3F28(s32 a0);
s32 func_01EA42D8(s32);
s32 func_01EA57B8();
s32 func_01EA57F8();

// Return the func_01EA42D8 result on func_01EA57B8() if nonzero; otherwise the func_01EA3F28 result on arg0, unless the func_01EA42D8 result on func_01EA57F8() is nonzero.
s32 func_01E9E7E8(s32 arg0) {
    s32 temp_s0;
    s32 temp_v0;
    s32 var_v0;

    var_v0 = func_01EA42D8(func_01EA57B8());
    if (var_v0 == 0) {
        temp_s0 = func_01EA3F28(arg0);
        temp_v0 = func_01EA42D8(func_01EA57F8());
        var_v0 = (temp_v0 == 0) ? temp_s0 : temp_v0;
    }
    return var_v0;
}
