/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 48 / disc 52.
 * Function text: 48 B; native catalogue: 52 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L00_0050BA20 nonmatching/pal/l00_multiplayer_menu/func_L00_0050BA20.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_L00_0050BA20(s8 *arg0) {
    s8 *temp_v1;
    s8 *var_a0;

    var_a0 = arg0;
    temp_v1 = var_a0;
    if (*var_a0 != 0) {
        do {
            var_a0 += 1;
        } while (*var_a0 != 0);
    }
    return var_a0 - temp_v1;
}
