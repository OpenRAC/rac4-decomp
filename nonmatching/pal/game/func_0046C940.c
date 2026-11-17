/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 25/112 (10 words differ).
 * Function text: 112 B; native catalogue: 112 B; 15 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_0046C940 nonmatching/pal/game/func_0046C940.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


f32 func_0046C940(void *arg0) {
    f32 temp_f1;
    s32 temp_f0;
    void *temp_v0;

    temp_f1 = (*(f32 *)((s8 *)(arg0) + (0x44)));
    temp_f0 = (s32) temp_f1;
    temp_v0 = (temp_f0 * 4) + ((*(s32 *)((s8 *)(arg0) + (0x40))) + 0x20);
    return ((f32) (*(s16 *)((s8 *)(temp_v0) + (2))) * 0.0625f) + ((temp_f1 - (f32) temp_f0) * (f32) (*(s16 *)((s8 *)(temp_v0) + (0))) * 0.5f);
}
