/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 3/56 (3 words differ).
 * Function text: 56 B; native catalogue: 56 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L00_00533318 nonmatching/pal/l00_multiplayer_menu/func_L00_00533318.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_L00_00533318(void *arg0) {
    s32 var_a0;
    s32 var_v0;

    var_v0 = 0;
    if (arg0 != NULL) {
        if (((*(s32 *)((s8 *)(arg0) + (0x2C))) != arg0) || (var_a0 = 0, ((*(s32 *)((s8 *)(arg0) + (0x28))) != 0x4A2FA8))) {
            var_a0 = 0x212;
        }
        var_v0 = var_a0;
    }
    return var_v0;
}
