/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 10/104 (8 words differ).
 * Function text: 104 B; native catalogue: 104 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Draft global definitions and initializers require independent native data validation.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_001614D0 nonmatching/pal/core/func_001614D0.c --diff
 */
#include "common.h"

s32 D_0021E0A8 = -1;
s32 D_0021E0AC = 0;
extern s32 func_001528A0(s32);

/* Clears the output, then submits a queued value unless one is already pending. */
s32 func_001614D0(s32 *arg0) {
    *arg0 = 0;
    if (D_0021E0A8 == -1) {
        return 1;
    }
    if (D_0021E0AC == 1) {
        return 0;
    }
    if (func_001528A0(D_0021E0A8) == 0) {
        *arg0 = 1;
        D_0021E0AC = 1;
        return 0;
    }
    return 1;
}
