/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 188 / disc 180.
 * Function text: 188 B; native catalogue: 180 B; 12 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_004F5108 nonmatching/pal/shared/func_L01_004F5108.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_L01_004F50E0(s16);                         /* extern */

s32 func_L01_004F5108(s32 arg0, s32 arg1, s32 *arg2) {
    f32 temp_f2;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_v0;

    if (arg2 != NULL) {
        var_a0 = *arg2;
    } else {
        var_a0 = (s32) (*(s16 *)((s8 *)((arg0 + (arg1 * 2))) + (0xC8)));
    }
    if (func_L01_004F50E0((s16) var_a0) == 0) {
        return 0;
    }
    temp_f2 = (*(f32 *)((s8 *)((arg0 + (arg1 * 4))) + (0x2B4)));
    if (temp_f2 > 0.0f) {
        var_a0_2 = 1;
        if (!((temp_f2 + 16.1f) < (*(f32 *)((s8 *)(((arg1 * 0x10) + arg0)) + (0x278))))) {
            var_a0_2 = 0;
        }
        var_v0 = 0;
        if (!(var_a0_2 & 0xFF)) {
            goto block_9;
        }
    } else {
block_9:
        var_v0 = 1;
    }
    return var_v0;
}
