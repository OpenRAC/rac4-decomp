/* Not matching yet: BYTES 1/80 (tools/try_func.py func_01EC9238 --diff). Not part of the build. */
extern s32 func_01EA42D8(s32);
extern s32 func_01EA57B8();
extern s32 func_01EA57F8();
extern s32 func_01ECF658();

// Chains the 57B8 and 57F8 checks through 42D8, falling back to the func_01ECF658 result when the second check is zero.
s32 func_01EC9238(void) {
    s32 temp_s0;
    s32 temp_v0;
    s32 var_v0;

    var_v0 = func_01EA42D8(func_01EA57B8());
    if (var_v0 == 0) {
        temp_s0 = func_01ECF658();
        temp_v0 = func_01EA42D8(func_01EA57F8());
        var_v0 = (temp_v0 == 0) ? temp_s0 : temp_v0;
    }
    return var_v0;
}
