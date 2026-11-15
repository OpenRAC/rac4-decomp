/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 260 / disc 272.
 * Function text: 260 B; native catalogue: 272 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_0014B380 nonmatching/pal/core/func_0014B380.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


f32 func_0014B380(f32 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    f32 var_f0;
    f32 var_f14;
    f32 var_f1;

    var_f14 = fparg2;
    if (*arg0 < 0.1f) {
        *arg0 = 0.1f;
    }
    if (var_f14 < 0.1f) {
        var_f14 = 0.1f;
    }
    if (__builtin_fabsf(fparg1 - fparg0) < 0.15f) {
        var_f0 = (fparg1 + fparg0) * 0.5f;
    } else {
        if (fparg3 < 0.35f) {
            if (fparg0 < fparg1) {
                var_f1 = fparg0 * fparg3;
                goto block_15;
            }
            goto block_14;
        }
        if (!(fparg0 < fparg1)) {
            var_f1 = fparg0 * fparg3;
block_15:
            var_f0 = var_f1 / *arg0;
        } else {
block_14:
            var_f0 = (fparg1 * fparg3) / var_f14;
        }
    }
    if (var_f0 < 0.0f) {
        var_f0 = 0.0f;
    }
    if (var_f0 > 1.0f) {
        var_f0 = 1.0f;
    }
    *arg0 = var_f14;
    return var_f0;
}
