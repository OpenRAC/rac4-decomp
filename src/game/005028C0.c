#include "common.h"

extern s32 func_00502738(s32 arg0, s32 arg1);
extern s32 func_00502448(s32 *arg0);

/* Looks up a pointer through func_00502738, then returns arg0 plus the arg1-th word after a count check, or the looked-up pointer. */
s32 func_005028C0(s32 arg0, u32 arg1, s32 arg2) {
    s32 var_s0;
    s32 n;

    var_s0 = func_00502738(arg0, arg2);
    if (var_s0 != 0) {
        n = func_00502448(var_s0);
        var_s0 += 4;
        if (arg1 < n) {
            var_s0 = arg0 + func_00502448(var_s0 + (arg1 << 2));
        }
    }
    return var_s0;
}
