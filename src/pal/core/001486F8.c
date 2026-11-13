#include "common.h"
extern f32 D_001A01F8[];

/* Scan eight table entries, preserving the native independent FP lifetimes. */
s32 func_001486F8(f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 *var_a1;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f1;
    f32 temp_f2;
    f32 var_f2;
    s32 var_a0;
    s32 var_a2;
    s32 var_a3;
    var_a3 = 0;
    var_a2 = 0;
    var_f2 = fparg2 - D_001A01F8[0];
    var_a1 = D_001A01F8 + 1;
    var_a0 = 1;
    var_f2 = var_f2 * var_f2;
    do {
        temp_f0 = fparg2 - *var_a1;
        temp_f0_2 = temp_f0 * temp_f0;
        if (temp_f0_2 < var_f2) {
            var_f2 = temp_f0_2;
            var_a2 = var_a0;
        }
        var_a0 += 1;
        var_a1 += 1;
    } while (var_a0 < 8);
    temp_f1 = fparg0 - fparg1;
    temp_f0_3 = D_001A01F8[var_a2] - fparg1;
    if (temp_f0_3 * temp_f0_3 < temp_f1 * temp_f1) var_a3 = 1;
    return var_a2 + var_a3 * 8;
}
