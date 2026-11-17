/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 136 / disc 140.
 * Function text: 136 B; native catalogue: 140 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_01F07320 nonmatching/pal/net/func_01F07320.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_0011A8A0(s32, s32);                        /* extern */

s32 func_01F07320(s32 arg0, s32 arg1) {
    s32 *temp_s0;
    s32 *temp_v1;
    s32 var_s1;
    s32 var_s2;

    var_s1 = 0;
    var_s2 = 0;
loop_1:
    temp_v1 = arg0 + (var_s1 * 8);
    temp_s0 = temp_v1;
    var_s1 += 1;
    if (((*(s32 *)((s8 *)(temp_s0) + (0))) != 0) && (func_0011A8A0((*(s32 *)((s8 *)(temp_v1) + (4))), arg1) == 0)) {
        var_s2 = (*(s32 *)((s8 *)(temp_s0) + (0)));
    }
    if ((var_s1 < 8) && (var_s2 == 0)) {
        goto loop_1;
    }
    return var_s2;
}
