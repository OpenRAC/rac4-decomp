/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 152 / disc 156.
 * Function text: 152 B; native catalogue: 156 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_0014C6B0 nonmatching/pal/core/func_0014C6B0.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


f32 func_0014C6B0(f32 fparg0) {
    f32 var_f1;
    f32 var_f4;

    var_f1 = fparg0 + 1e-7f;
    var_f4 = 1.0f;
    if (var_f1 < 0.1f) {
        do {
            var_f1 *= 10.0f;
            var_f4 *= 0.56234133f;
        } while (var_f1 < 0.1f);
    }
    return ((var_f1 * ((var_f1 * -0.48015624f) + 1.0000972f)) + 0.46449155f) * var_f4;
}
