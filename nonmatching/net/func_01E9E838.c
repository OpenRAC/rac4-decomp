/* Not matching yet: BYTES 9/92 (tools/try_func.py func_01E9E838 --diff). Not part of the build. */
extern s32 func_01EA42D8(s32);
extern s32 func_01EA57B8();
extern s32 func_01EA57F8();
extern s32 D_00167F38_[];
#define D_00167F38 (D_00167F38_[0])

// Runs the two checks and calls the object's slot at 0x1C when the first check passes; returns the first nonzero result.
s32 func_01E9E838(s32 arg0) {
    s32 temp_s0;
    s32 temp_v0;
    s32 var_v0;

    var_v0 = func_01EA42D8(func_01EA57B8());
    if (var_v0 == 0) {
        temp_s0 = ((s32 (*)(s32))(*(s32 *)(D_00167F38 + 0x1C)))(arg0);
        temp_v0 = func_01EA42D8(func_01EA57F8());
        var_v0 = (temp_v0 == 0) ? temp_s0 : temp_v0;
    }
    return var_v0;
}
