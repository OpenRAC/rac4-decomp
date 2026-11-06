/* cflags: -mno-split-addresses */
#include "common.h"

s32 func_L00_005E8398(s32, s32);


void func_L01_004669F0(s32 *arg0, s32 arg1, s32 arg2) {
    s32 *var_s1;
    s32 temp_a0;
    s32 var_s0;

    if (arg1 > 0) {
        var_s1 = arg0;
        var_s0 = arg1;
        do {
            temp_a0 = *var_s1;
            var_s1 += 1;
            func_L00_005E8398(temp_a0, arg2);
            var_s0 -= 1;
        } while (var_s0 != 0);
    }
}
