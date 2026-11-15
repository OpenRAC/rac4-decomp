/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 52 / disc 56.
 * Function text: 52 B; native catalogue: 56 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_01EE39E0 nonmatching/pal/net/func_01EE39E0.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


void *func_01EE3974();                              /* extern */

void *func_01EE39E0(void) {
    void *temp_v1;
    void *var_v0;

    var_v0 = func_01EE3974();
    if (var_v0 != NULL) {
        temp_v1 = (*(void **)((s8 *)(var_v0) + (8)));
        var_v0 = NULL;
        if (temp_v1 != NULL) {
            var_v0 = (*(void **)((s8 *)(temp_v1) + (0x28)));
        }
    }
    return var_v0;
}
