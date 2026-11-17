/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 36 / disc 40.
 * Function text: 36 B; native catalogue: 40 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L05_004F4FB0 nonmatching/pal/l05_dark_cathedral/func_L05_004F4FB0.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_L05_004F4FB0(void *arg0) {
    s32 var_a1;

    var_a1 = 0;
    if ((*(u8 *)((s8 *)(arg0) + (0x69))) == 5) {
        var_a1 = (*(u8 *)((s8 *)(arg0) + (0x20))) == 7;
    }
    return var_a1;
}
