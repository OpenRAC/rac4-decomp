#include "common.h"

s32 func_0069DA50(s32 handle, f32 a, f32 b);

s32 func_L00_00717580(void *arg0, f32 fparg0, f32 fparg1) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_a0_6;
    s32 temp_a0_7;
    s32 var_s1;

    var_s1 = 0;
    temp_a0 = (*(s32 *)((s8 *)(arg0) + (0x14)));
    if (temp_a0 != 0) {
        var_s1 = func_0069DA50(temp_a0, fparg0, fparg1);
    }
    temp_a0_2 = (*(s32 *)((s8 *)(arg0) + (0x5C)));
    if (temp_a0_2 != 0) {
        var_s1 |= func_0069DA50(temp_a0_2, fparg0, fparg1);
    }
    temp_a0_3 = (*(s32 *)((s8 *)(arg0) + (0x12C)));
    if (temp_a0_3 != -1) {
        var_s1 |= func_0069DA50(temp_a0_3, fparg0, fparg1);
    }
    temp_a0_4 = (*(s32 *)((s8 *)(arg0) + (0x130)));
    if (temp_a0_4 != -1) {
        var_s1 |= func_0069DA50(temp_a0_4, fparg0, fparg1);
    }
    temp_a0_5 = (*(s32 *)((s8 *)(arg0) + (0x134)));
    if (temp_a0_5 != -1) {
        var_s1 |= func_0069DA50(temp_a0_5, fparg0, fparg1);
    }
    temp_a0_6 = (*(s32 *)((s8 *)(arg0) + (0x138)));
    if (temp_a0_6 != -1) {
        var_s1 |= func_0069DA50(temp_a0_6, fparg0, fparg1);
    }
    temp_a0_7 = (*(s32 *)((s8 *)(arg0) + (0x13C)));
    if (temp_a0_7 != -1) {
        var_s1 |= func_0069DA50(temp_a0_7, fparg0, fparg1);
    }
    return var_s1 != 0;
}
