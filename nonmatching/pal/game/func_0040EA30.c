/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 56 / disc 64.
 * Function text: 56 B; native catalogue: 64 B; 2 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_0040EA30 nonmatching/pal/game/func_0040EA30.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_0040EA30(void *arg0, void *arg1) {
    s32 temp_a3;
    s32 temp_a4;
    s32 temp_a5;

    temp_a5 = (*(s32 *)((s8 *)(arg0) + (8)));
    (*(s32 *)((s8 *)(arg0) + (8))) = (s32) (*(s32 *)((s8 *)(arg1) + (8)));
    temp_a4 = (*(s32 *)((s8 *)(arg0) + (0)));
    temp_a3 = (*(s32 *)((s8 *)(arg0) + (4)));
    (*(s32 *)((s8 *)(arg0) + (0))) = (s32) (*(s32 *)((s8 *)(arg1) + (0)));
    (*(s32 *)((s8 *)(arg0) + (4))) = (s32) (*(s32 *)((s8 *)(arg1) + (4)));
    (*(s32 *)((s8 *)(arg1) + (4))) = temp_a3;
    (*(s32 *)((s8 *)(arg1) + (8))) = temp_a5;
    (*(s32 *)((s8 *)(arg1) + (0))) = temp_a4;
    return 0;
}
