/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 3/200 (3 words differ).
 * Function text: 200 B; native catalogue: 200 B; 14 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L00_005F0BD8 nonmatching/pal/shared/func_L00_005F0BD8.c --diff
 */
#include "common.h"

extern f32 func_0046C940(void *object);

s32 func_L00_005F0BD8(void *object, f32 target) {
    f32 current = func_0046C940(object);
    f32 delta = *(f32 *)((u8 *)object + 0x48);
    s32 targetFixed = (s32)(target * 4096.0f + 0.5f);
    s32 currentFixed = (s32)(current * 4096.0f + 0.5f);
    s32 previousFixed = (s32)((current - delta * 1.2f * 0.5f) * 4096.0f + 0.5f);
    if (delta < 0.0f) {
        if (targetFixed < currentFixed || !(targetFixed < previousFixed)) {
            return 0;
        }
    } else {
        if (currentFixed < targetFixed || !(previousFixed < targetFixed)) {
            return 0;
        }
    }
    return 1;
}
