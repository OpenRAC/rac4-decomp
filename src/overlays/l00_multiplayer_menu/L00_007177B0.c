#include "common.h"

s32 func_L00_0069CE38(s32 handle, s32 a, s32 b);

s32 func_L00_007177B0(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_a0_6;
    s32 temp_a0_7;
    s32 var_s3;

    temp_a0 = (*(s32 *)((s8 *)(arg0) + (0x14)));
    var_s3 = 0;
    if (temp_a0 != 0) {
        var_s3 = func_L00_0069CE38(temp_a0, arg1, arg2);
    }
    temp_a0_2 = (*(s32 *)((s8 *)(arg0) + (0x5C)));
    if (temp_a0_2 != 0) {
        var_s3 |= func_L00_0069CE38(temp_a0_2, arg1, arg2);
    }
    temp_a0_3 = (*(s32 *)((s8 *)(arg0) + (0x12C)));
    if (temp_a0_3 != -1) {
        var_s3 |= func_L00_0069CE38(temp_a0_3, arg1, arg2);
    }
    temp_a0_4 = (*(s32 *)((s8 *)(arg0) + (0x130)));
    if (temp_a0_4 != -1) {
        var_s3 |= func_L00_0069CE38(temp_a0_4, arg1, arg2);
    }
    temp_a0_5 = (*(s32 *)((s8 *)(arg0) + (0x134)));
    if (temp_a0_5 != -1) {
        var_s3 |= func_L00_0069CE38(temp_a0_5, arg1, arg2);
    }
    temp_a0_6 = (*(s32 *)((s8 *)(arg0) + (0x138)));
    if (temp_a0_6 != -1) {
        var_s3 |= func_L00_0069CE38(temp_a0_6, arg1, arg2);
    }
    temp_a0_7 = (*(s32 *)((s8 *)(arg0) + (0x13C)));
    if (temp_a0_7 != -1) {
        var_s3 |= func_L00_0069CE38(temp_a0_7, arg1, arg2);
    }
    return var_s3 != 0;
}
