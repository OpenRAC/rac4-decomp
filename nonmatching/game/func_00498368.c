/* Not matching yet: BYTES 9/120 (tools/try_func.py func_00498368 --diff). Not part of the build. */
extern s32 func_00497458(void);
extern s32 func_004984B8(s32 arg0);
extern void *func_00510BE8(s32 arg0);
extern u8 D_0021F418;
extern void *D_0021DDA4;
extern void *D_0021DDCC;

// Looks up a sub-object through the global slots, then releases its 0x1C4 value and clears it.
s32 func_00498368(s32 arg0) {
    s32 var_v0;
    void *var_s1;

    var_s1 = NULL;
    if (func_00497458() != 0) {
        if (D_0021F418 != 0) {
            var_s1 = D_0021DDCC;
        } else if (arg0 < *(s32 *) D_0021DDA4) {
            var_s1 = *(void **) ((u8 *) func_00510BE8(arg0) + 0x2F00);
        }
    }
    var_v0 = 0;
    if (var_s1 != NULL) {
        var_v0 = func_004984B8(*(s32 *) ((u8 *) var_s1 + 0x1C4));
        *(s32 *) ((u8 *) var_s1 + 0x1C4) = 0;
    }
    return var_v0;
}
