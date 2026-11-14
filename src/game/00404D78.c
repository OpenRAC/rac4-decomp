/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_00409F88(s32 arg0, s32 arg1, s32 arg2);

/* XORs each word in [arg0, arg1) with 0x09F8ED17 when func_00409F88 says so. */
s32 func_00404D78(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_s0;

    var_s0 = arg0;
    if (var_s0 < arg1) {
        do {
            if (func_00409F88(var_s0 - arg2, arg3, arg4) > 0) {
                *(s32 *)var_s0 = *(s32 *)var_s0 ^ 0x09F8ED17;
            }
            var_s0 += 4;
        } while (var_s0 < arg1);
    }
    return 0;
}
