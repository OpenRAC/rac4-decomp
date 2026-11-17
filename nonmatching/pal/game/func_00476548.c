/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 10/176 (5 words differ).
 * Function text: 176 B; native catalogue: 176 B; 15 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_00476548 nonmatching/pal/game/func_00476548.c --diff
 */
#include "common.h"

extern f32 func_00454370(f32, f32);
extern f32 fabsf(f32);

f32 func_00476548(f32 target, f32 position, s32 mode) {
    f32 angle = func_00454370(target, position);

    if (mode == 0 || angle * (f32)mode > 0.0f) {
        return angle;
    }
    if (fabsf(angle) <= 0.0017453292f) {
        return 0.0f;
    }
    if (angle > 0.0f) {
        return angle - 6.2831855f;
    }
    return angle + 6.2831855f;
}
