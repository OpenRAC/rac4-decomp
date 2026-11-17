/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 84 / disc 88.
 * Function text: 84 B; native catalogue: 88 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_01EBF978 nonmatching/pal/net/func_01EBF978.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


void func_01EBF978(void *arg0, void *arg1) {
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *var_a0;
    void *var_v1;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0xC)));
    var_v1 = temp_v0;
    if (temp_v0 == arg1) {
        (*(void **)((s8 *)(arg0) + (0xC))) = (void *) (*(void **)((s8 *)(arg1) + (0x8C)));
        return;
    }
    if (var_v1 != NULL) {
        temp_v0_2 = (*(void **)((s8 *)(var_v1) + (0x8C)));
        if (arg1 != temp_v0_2) {
            var_a0 = temp_v0_2;
loop_5:
            var_v1 = var_a0;
            if (var_v1 != NULL) {
                temp_v0_3 = (*(void **)((s8 *)(var_v1) + (0x8C)));
                var_a0 = temp_v0_3;
                if (arg1 == temp_v0_3) {
                    goto block_7;
                }
                goto loop_5;
            }
        } else {
block_7:
            (*(void **)((s8 *)(var_v1) + (0x8C))) = (void *) (*(void **)((s8 *)(arg1) + (0x8C)));
        }
    }
}
