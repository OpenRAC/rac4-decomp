/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 48 / disc 52.
 * Function text: 48 B; native catalogue: 52 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L00_00533A88 nonmatching/pal/l00_multiplayer_menu/func_L00_00533A88.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


u8 *func_L00_00533A88(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 var_v1;
    u8 *temp_a3;
    u8 *var_a0;
    u8 *var_a1;
    u8 temp_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    temp_a3 = var_a0;
    var_v1 = arg2 - 1;
    if (arg2 != 0) {
        do {
            temp_v0 = *var_a1;
            var_a1 += 1;
            var_v1 -= 1;
            *var_a0 = temp_v0;
            var_a0 += 1;
        } while (var_v1 != -1);
    }
    return temp_a3;
}
