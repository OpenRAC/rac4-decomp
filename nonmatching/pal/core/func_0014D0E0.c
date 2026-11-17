/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 200 / disc 244.
 * Function text: 200 B; native catalogue: 244 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_0014D0E0 nonmatching/pal/core/func_0014D0E0.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_0014D0E0(f32 fparg0) {
    s32 var_v0;

    var_v0 = 0x105;
    if (!(fparg0 > 96.0f)) {
        var_v0 = 0xF1;
        if (!(fparg0 > 88.0f)) {
            var_v0 = 0xDD;
            if (!(fparg0 > 80.0f)) {
                var_v0 = 0xC9;
                if (!(fparg0 > 72.0f)) {
                    var_v0 = 0xB5;
                    if (!(fparg0 > 64.0f)) {
                        if (fparg0 > 56.0f) {
                            /* Duplicate return node #6. Try simplifying control flow for better match */
                            return 0xA1;
                        }
                        if (!(fparg0 > 48.0f)) {
                            var_v0 = 0xA1;
                            if (fparg0 > 40.0f) {
                                var_v0 = 0xA1;
                            }
                            /* Duplicate return node #10. Try simplifying control flow for better match */
                            return var_v0;
                        }
                        return 0xA1;
                    }
                }
            }
        }
    }
    return var_v0;
}
