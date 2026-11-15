/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 72 / disc 68.
 * Function text: 72 B; native catalogue: 68 B; 2 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_003FE788 nonmatching/pal/game/func_003FE788.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_003FE788(void *arg0, s32 *arg1, s32 arg2) {
    u32 temp_a3;
    u32 var_v1;
    void *var_a0;

    temp_a3 = (*(u32 *)((s8 *)(arg0) + (0xC)));
    var_v1 = 0;
    if (temp_a3 != 0) {
        var_a0 = (*(void **)((s8 *)(arg0) + (0x10)));
loop_2:
        var_v1 += 1;
        if ((*(s32 *)((s8 *)(var_a0) + (0))) == arg2) {
            *arg1 = (*(s32 *)((s8 *)(var_a0) + (4)));
            return 0;
        }
        var_a0 += 8;
        if (var_v1 >= temp_a3) {
            /* Duplicate return node #6. Try simplifying control flow for better match */
            return 0x217;
        }
        goto loop_2;
    }
    return 0x217;
}
