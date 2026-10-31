/* Not matching yet: BYTES 11/128 (tools/try_func.py func_00549CA0 --diff). Not part of the build. */
extern s32 func_00549BB8();
extern s32 func_0054A0C0(s32 arg0, s32 arg1);
extern s32 func_0054A788(s32, s32, s32);

/* Sums func_0054A788 over indices 2 to 19 where func_0054A0C0 reports a match, starting from the value of func_00549BB8. */
s32 func_00549CA0(s32 arg0, s32 arg1) {
    s32 var_s0;
    s32 var_s1;

    var_s1 = func_00549BB8();
    var_s0 = 2;
    do {
        if (func_0054A0C0(var_s0, arg1) != 0) {
            var_s1 += func_0054A788(arg0, var_s0, arg1);
        }
        var_s0 += 1;
    } while (var_s0 < 0x14);
    return var_s1;
}
