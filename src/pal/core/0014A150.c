#include "common.h"

/* Applies each weight to matching front/back elements, then handles the odd middle element. */
void func_0014A150(f32 *arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    s32 temp_t0, temp_v0;
    f32 *var_t1, *var_t2;
    u32 offset;

    temp_t0 = arg3 >> 1;
    offset = ((u32)arg3 << 2) - 4U;
    var_t1 = (f32 *)((u32)arg0 + offset);
    var_t2 = (f32 *)((u32)arg2 + offset);

    temp_v0 = temp_t0;
    temp_t0 -= 1;
    if (temp_v0 > 0) {
        s32 temp_v0_2;
        f32 temp_f0, temp_f0_2, temp_f1;

        do {
            temp_v0_2 = temp_t0;
            temp_f0 = *arg0;
            temp_t0 -= 1;
            arg0 += 1;
            *arg2 = temp_f0 * *arg1;
            arg2 += 1;
            temp_f0_2 = *var_t1;
            temp_f1 = *arg1;
            var_t1 -= 1;
            arg1 += 1;
            *var_t2 = temp_f0_2 * temp_f1;
            var_t2 -= 1;
        } while (temp_v0_2 > 0);
    }
    if (arg3 & 1) {
        *arg2 = *arg0 * *arg1;
    }
}
