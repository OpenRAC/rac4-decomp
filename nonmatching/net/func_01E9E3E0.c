/* Not matching yet: BYTES 4/72 (tools/try_func.py func_01E9E3E0 --diff). Not part of the build. */
extern void func_0011A518(void *, s32, s32);

// Marks the handle at arg0 as state 1 with flag 2 after a call; returns 0x17 if arg0 is NULL.
s32 func_01E9E3E0(s32 *arg0) {
    s32 var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        func_0011A518(arg0, 0, 0x48);
        arg0[0] = 1;
        arg0[7] = 2;
        var_v0 = 0;
    }
    return var_v0;
}
