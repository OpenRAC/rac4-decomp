/* Not matching yet: BYTES 1/80 (tools/try_func.py func_01E9E798 --diff). Not part of the build. */
s32 func_01EA3E08();
s32 func_01EA42D8(s32);
s32 func_01EA57B8();
s32 func_01EA57F8();

// Return the func_01EA42D8 result on func_01EA57B8() if nonzero; otherwise the func_01EA3E08 result, unless the func_01EA42D8 result on func_01EA57F8() is nonzero.
s32 func_01E9E798(void) {
    s32 temp_s0;
    s32 temp_v0;
    s32 var_v0;

    var_v0 = func_01EA42D8(func_01EA57B8());
    if (var_v0 == 0) {
        temp_s0 = func_01EA3E08();
        temp_v0 = func_01EA42D8(func_01EA57F8());
        var_v0 = (temp_v0 == 0) ? temp_s0 : temp_v0;
    }
    return var_v0;
}
