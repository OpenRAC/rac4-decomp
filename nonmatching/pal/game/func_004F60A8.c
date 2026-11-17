/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 168 / disc 164.
 * Function text: 168 B; native catalogue: 164 B; 15 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_004F60A8 nonmatching/pal/game/func_004F60A8.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


extern f32 D_00220A10;

void func_004F60A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 var_f0;
    s32 temp_a1;

    temp_a1 = arg1 - 1;
    if ((arg0 <= 0) || (arg0 >= temp_a1)) {
        D_00220A10 = 0.0f;
    } else {
        if (arg2 >= arg0) {
            var_f0 = (f32) arg0 / (f32) arg2;
        } else if ((temp_a1 - arg3) < arg0) {
            var_f0 = (f32) (temp_a1 - arg0) / (f32) arg3;
        } else {
            var_f0 = 1.0f;
        }
        D_00220A10 = var_f0;
    }
    D_00220A10 = 1.0f - D_00220A10;
}
