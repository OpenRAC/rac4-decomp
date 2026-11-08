/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_0011A370(s32, s32, s32);
s32 func_0011AB04(s32);

s32 func_01EE3B50(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_s0;

    var_s0 = arg2;
    if (var_s0 == 0) {
        var_s0 = func_0011AB04(arg1);
    }
    func_0011A370(arg0, arg1, var_s0);
    return arg0 + var_s0;
}
