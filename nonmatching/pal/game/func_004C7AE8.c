/* Not matched: PAL SCES_532.85.
 * SIZE ours 264 / disc 272 at all 16 physical bodies, including frontend.
 * Existing symbolic table and loaded entry pointers replace fixed addresses.
 * All per-program table bindings and three call targets were checked unmasked.
 * Register allocation, branch layout and instruction positions still differ.
 * The post-call byte/count reloads and complete scan remain in the draft.
 * No complete object extent, initializer or runtime bounds are asserted.
 * No instruction padding, flag change or emitted data is introduced.
 * Reproduce: python3 tools/check_func.py --version pal func_004C7AE8 nonmatching/pal/game/func_004C7AE8.c --diff
 */
#include "common.h"

s32 func_00506BB8(void);
void *func_0054BF00(s32);                           /* extern */
s32 func_0054C070(s32, s32);                        /* extern */

extern u8 D_0030B9D8[];

/* Select the first eligible index while retaining the complete native scan. */
s32 func_004C7AE8(void) {
    s32 temp_v1;
    s32 var_s1;
    s32 var_s4;
    s32 var_v1;
    void *temp_s0;
    u8 *temp_s2;
    u8 *temp_s3;
    u8 *var_v0;

    var_s1 = 0;
    var_s4 = -1;
    temp_s3 = D_0030B9D8 + func_00506BB8() * 0xB30;
    if ((*(s32 *)((s8 *)(temp_s3) + (0xB04))) > 0) {
        do {
            temp_s2 = temp_s3 + 0xAB4;
            if (var_s4 == -1) {
                if (var_s1 < 0) {
                    temp_v1 = (*(s32 *)((s8 *)(temp_s2) + (0x54)));
                    var_v1 = temp_v1 * 0x18;
                    if (temp_v1 < 0) {
                        var_v0 = NULL;
                    } else {
                        goto block_7;
                    }
                } else {
                    var_v1 = var_s1 * 0x18;
block_7:
                    var_v0 = (*(u8 **)((s8 *)(temp_s2) + (0x34))) + var_v1;
                }
                temp_s0 = (*(void **)((s8 *)(var_v0) + (8)));
                if (((*(s32 *)((s8 *)(temp_s0) + (8))) != 1) && ((*(s32 *)((s8 *)(func_0054BF00(func_0054C070((*(s32 *)((s8 *)(temp_s3) + (0xB2C))), (*(s32 *)((s8 *)(temp_s0) + (4)))))) + (0x14))) != 0)) {
                    var_s4 = ((*(u8 *)((s8 *)(temp_s0) + (2))) != 0) ? var_s1 : var_s4;
                }
            }
            var_s1 += 1;
        } while (var_s1 < (*(s32 *)((s8 *)(temp_s2) + (0x50))));
    }
    return var_s4;
}
