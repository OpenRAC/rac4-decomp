/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 204 / disc 208.
 * Function text: 204 B; native catalogue: 208 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_0014CBD0 nonmatching/pal/core/func_0014CBD0.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */
float func_00136638(float x);

f32 func_0014CBD0(f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 temp_f0;
    f32 var_f14;

    var_f14 = fparg2;
    if (var_f14 <= 0.0f) {
        var_f14 = 0.000001f;
    }
    if (var_f14 >= 1.0f) {
        var_f14 = 0.999999f;
    }
    temp_f0 = func_00136638(1.0f - var_f14) * -10.0f;
    if (temp_f0 < fparg0) {
        return 0.0f;
    }
    if (!(fparg1 < temp_f0)) {
        return (temp_f0 - fparg0) / (fparg1 - fparg0);
    }
    return 1.0f;
}
