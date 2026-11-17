/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 38/300 (18 words differ).
 * Function text: 300 B; native catalogue: 300 B; 14 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L00_006FAC10 nonmatching/pal/shared/func_L00_006FAC10.c --diff
 */
#include "common.h"

void func_L00_006FAC10(u8 *arg0, s32 arg1, s32 *arg2, s32 arg3) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a2;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_3;
    s32 var_a1;
    s32 var_a2;
    u8 *var_t0;

    temp_a2 = *arg2;
    arg3 &= 0xFF;
    temp_v1 = temp_a2 / 8;
    var_t0 = arg0 + temp_v1;
    temp_v1 = temp_a2 - (temp_v1 * 8);
    temp_a0 = 8 - temp_v1;
    if (temp_a0 < arg3) {
        var_a1 = temp_a0 & 0xFF;
        var_a2 = 0;
    } else {
        var_a1 = arg3;
        var_a2 = (8 - (arg3 + temp_v1)) & 0xFF;
    }
    *arg2 += var_a1;
    arg3 -= var_a1;
    temp_v1_3 = (0xFF >> (8 - var_a1)) & 0xFF;
    temp_a0 = ((temp_v1_3 & (arg1 >> arg3)) << var_a2) | (*var_t0 & ~(temp_v1_3 << var_a2));
    arg3 &= 0xFF;
    *var_t0 = temp_a0;
    if (arg3 != 0) {
        do {
            var_t0 += 1;
            if ((u32) arg3 >= 9U) {
                var_a2 = 0;
                var_a1 = 8;
            } else {
                var_a1 = arg3;
                var_a2 = (8 - arg3) & 0xFF;
            }
            temp_v0 = (0xFF >> (8 - var_a1)) & 0xFF;
            arg3 -= var_a1;
            *arg2 += var_a1;
            temp_a0_2 = arg1 >> arg3;
            arg3 &= 0xFF;
            *var_t0 = (*var_t0 & ~(temp_v0 << var_a2)) | ((temp_v0 & temp_a0_2) << var_a2);
        } while (arg3 != 0);
    }
}
