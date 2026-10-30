/* Not matching yet: BYTES 9/80 (tools/try_func.py func_01EC9530 --diff). Not part of the build. */
extern s32 func_01EA42D8(s32);
extern s32 func_01EA57B8();
extern s32 func_01EA57F8();
extern s32 func_01ECD2D0(s32);

// Returns 0 when the check passes, else the result of the second check.
s32 func_01EC9530(s32 arg0) {
    s32 var_v0;
    s32 temp_s0;

    var_v0 = func_01EA42D8(func_01EA57B8());
    if (var_v0 == 0) {
        temp_s0 = func_01ECD2D0(arg0);
        var_v0 = func_01EA42D8(func_01EA57F8());
        if (var_v0 == 0) {
            var_v0 = temp_s0;
        }
    }
    return var_v0;
}
