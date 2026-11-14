#include "common.h"

/* Three padded rows of native float cofactors, followed by reciprocal scaling.
 * The duplicated src[1] products are present in the retail implementation. */
void func_L41_0050BCD8(f32 *arg0, f32 *arg1) {
    f32 temp_f1;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f6;
    f32 temp_f7;
    s32 var_v1;
    temp_f6 = (arg1[5] * arg1[10]) - (arg1[6] * arg1[9]);
    arg0[0] = temp_f6;
    temp_f1 = arg1[1];
    arg0[1] = (f32) ((temp_f1 * arg1[9]) - (temp_f1 * arg1[10]));
    arg0[2] = (f32) ((arg1[1] * arg1[6]) - (arg1[2] * arg1[5]));
    temp_f5 = (arg1[6] * arg1[8]) - (arg1[4] * arg1[10]);
    arg0[4] = temp_f5;
    arg0[5] = (f32) ((arg1[0] * arg1[10]) - (arg1[2] * arg1[8]));
    arg0[6] = (f32) ((arg1[2] * arg1[4]) - (arg1[0] * arg1[6]));
    temp_f4 = (arg1[4] * arg1[9]) - (arg1[5] * arg1[8]);
    arg0[8] = temp_f4;
    arg0[9] = (f32) ((arg1[1] * arg1[8]) - (arg1[0] * arg1[9]));
    arg0[10] = (f32) ((arg1[0] * arg1[5]) - (arg1[1] * arg1[4]));
    temp_f7 = 1.0f / ((arg1[0] * temp_f6) + (arg1[1] * temp_f5) + (arg1[2] * temp_f4));
    /* Three rows at the observed four-float stride. */
    for (var_v1 = 0; var_v1 < 3; var_v1++) {
        arg0[var_v1 * 4] *= temp_f7;
        arg0[var_v1 * 4 + 1] *= temp_f7;
        arg0[var_v1 * 4 + 2] *= temp_f7;
    }
}
