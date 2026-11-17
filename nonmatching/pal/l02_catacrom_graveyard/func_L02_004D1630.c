/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 32 / disc 36.
 * Function text: 32 B; native catalogue: 36 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L02_004D1630 nonmatching/pal/l02_catacrom_graveyard/func_L02_004D1630.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_L02_004D1630(void *arg0) {
    s32 var_a0;
    void *temp_v1;

    temp_v1 = (*(void **)((s8 *)(arg0) + (0xAC)));
    var_a0 = 0;
    if ((*(s32 *)((s8 *)(temp_v1) + (0x6C))) > 0) {
        var_a0 = (*(s32 *)((s8 *)(temp_v1) + (0x70))) < 1;
    }
    return var_a0;
}
