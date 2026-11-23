/* Not matching yet: PAL WIP; level_01 .text 0x00576530, 544B. Not part of the build. */
/*
 * Preheader GPR/FPR assignment and address-addend materialization differ. Both entire scan/result
 * loops are identical to native only under an explanatory static comparison deleting native
 * NOPs+1CC/+1D0 and rebasing relative branches. Actual objects are unmodified and nonexact. Both
 * DIVs begin+1CC versus native+1D4.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 9b603025315d6a40be851e322267841b855fec8fee7b63767e3b2988f3e75eb5
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_00576530 nonmatching/pal/shared/func_L01_00576530.c --diff
 */
#include "common.h"

extern u8 D_0024F220[];

s32 func_L01_00576530(s32 arg0, f32 *arg1, void *arg2, s32 *arg3) {
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f5;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 var_f1;
    f32 var_f2;
    s32 temp_a4;
    f32 point_x;
    f32 point_y;
    u32 packed_x;
    s32 var_a2;
    u32 temp_v0_2;
    u32 temp_v1_2;
    u8 *var_a0;

    temp_a4 = arg0 & 0xFFFF;
    if (temp_a4 == 0x801) {
        return 0;
    }
    *arg1 = 0.0f;
    point_x = *(f32 *)((u8 *)arg2 + 0);
    packed_x = *(u32 *)(D_0024F220 + temp_a4 * 0x30 + 0x20);
    var_f2 = (f32)(packed_x & 0x1FFu);
    var_f2 = var_f2 - 0.5f;
    point_y = *(f32 *)((u8 *)arg2 + 4);
    var_f2 = 2.0f * var_f2;
    temp_v1_2 = *(u32 *)(D_0024F220 + temp_a4 * 0x30 + 0x20);
    temp_v0_2 = temp_v1_2 >> 9;
    temp_f8 = point_x - var_f2;
    var_f1 = (f32)temp_v0_2;
    var_a2 = 0;
    var_a0 = D_0024F220 + temp_a4 * 0x30;
    temp_f7 = point_y - (2.0f * (var_f1 - 0.5f));
    do {
        temp_f6 = (f32) (*(u8 *)((s8 *)(var_a0) + (3)));
        if (!(temp_f6 <= *arg1)) {
            temp_f4 = ((f32) (*(u8 *)((s8 *)(var_a0) + (0))) * 0.252f) - 32.0f;
            temp_f5 = ((f32) (*(u8 *)((s8 *)(var_a0) + (1))) * 0.252f) - 32.0f;
            temp_f2 = (temp_f4 * temp_f8) + (temp_f5 * temp_f7);
            if (!(temp_f2 < 0.0f)) {
                temp_f0 = (temp_f8 * temp_f8) + (temp_f7 * temp_f7);
                if (!(temp_f0 < temp_f2)) {
                    temp_f4_2 = (f32) (*(u8 *)((s8 *)(var_a0) + (2)));
                    if (!((temp_f4_2 * 0.0009859599f * temp_f4_2) < (((temp_f4 * temp_f4) + (temp_f5 * temp_f5)) - ((temp_f2 * temp_f2) / temp_f0)))) {
                        *arg1 = temp_f6;
                        if (arg3 != NULL) {
                            *arg3 = var_a2;
                        }
                    }
                }
            }
        }
        var_a2 += 1;
        var_a0 += 4;
    } while (var_a2 < 2);
    return 1;
}
