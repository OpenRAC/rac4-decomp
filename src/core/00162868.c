#include "common.h"

extern u32 func_00162908(u32 arg0);
extern s32 func_01E9E5D0(s32 arg0, s32 arg1);
extern s32 D_0021E09C;
extern s32 D_00172160[];
extern u32 D_212710[];

/* Compares arg0 with a stored value and returns a flag from the table at D_212710. */
s32 func_00162868(u32 arg0) {
    s32 *p;
    u32 sp0;
    u32 var_s0;
    s32 var_s1;

    p = D_00172160;
    var_s0 = arg0;
    var_s1 = 0;
    sp0 = p[4];
    if (p[2] == 0) {
        func_01E9E5D0((s32)&sp0, p[3]);
        sp0 = func_00162908(sp0);
        var_s0 = func_00162908(var_s0);
    }
    if (var_s0 < 0xA) {
        if (var_s0 == sp0) {
            var_s1 = D_0021E09C;
        } else {
            var_s1 = D_212710[var_s0] != 0xFFFFFFFF;
        }
    }
    return var_s1;
}
