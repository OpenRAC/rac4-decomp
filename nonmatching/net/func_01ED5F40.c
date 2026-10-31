/* Not matching yet: BYTES 8/76 (tools/try_func.py func_01ED5F40 --diff). Not part of the build. */
extern void func_0011A518(void *, s32, s32);
extern s32 D_00169CD4_[];
#define D_00169CD4 (D_00169CD4_[0])

/* Initialises the object at arg0 from the global at D_00169CD4, returning -0x15 when arg0 is NULL. */
s32 func_01ED5F40(void *arg0) {
    s32 var_v0;
    s32 var_a0;

    var_v0 = -0x15;
    if (arg0 != NULL) {
        func_0011A518(arg0, 0, 0xC);
        var_a0 = D_00169CD4;
        ((s32 *)arg0)[1] = 1;
        var_v0 = 0;
        ((s32 *)arg0)[0] = var_a0;
    }
    return var_v0;
}
