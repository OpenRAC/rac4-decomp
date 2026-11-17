/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 22/136 (8 words differ).
 * Function text: 136 B; native catalogue: 136 B; 12 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_005270B0 nonmatching/pal/shared/func_L01_005270B0.c --diff
 */
#include "common.h"

extern f32 fabsf(f32);
u8 *func_00511CC0(s32 index);

s32 func_L01_005270B0(void *arg0) {
    u8 *temp_a0;
    s32 result;

    temp_a0 = *(u8 **)(func_00511CC0(*(s32 *)((u8 *)arg0 + 0x94)) + 0x2F00);
    if (*(s32 *)(temp_a0 + 0x1A0) & ~0x800) {
        return 1;
    }
    if (fabsf(*(f32 *)(temp_a0 + 0x100)) + fabsf(*(f32 *)(temp_a0 + 0x104)) > 0.1f) {
        return 1;
    }
    result = 1;
    if (!(fabsf(*(f32 *)(temp_a0 + 0x108)) + fabsf(*(f32 *)(temp_a0 + 0x10C)) > 0.1f)) {
        result = 0;
    }
    return result;
}
