/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 136 / disc 140.
 * Function text: 136 B; native catalogue: 140 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_0014EAA0 nonmatching/pal/core/func_0014EAA0.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


void func_0014EAA0(void *arg0, f32 *arg1, f32 *arg2) {
    f32 temp_f0;
    f32 temp_f0_2;

    *arg1 *= (*(f32 *)((s8 *)(arg0) + (0x34)));
    temp_f0 = 8000.0f / *arg2;
    *arg2 = temp_f0;
    temp_f0_2 = (temp_f0 * (*(f32 *)((s8 *)(arg0) + (0x18))) * (*(f32 *)((s8 *)(arg0) + (0x30)))) + (*(f32 *)((s8 *)(arg0) + (0x1C)));
    *arg2 = temp_f0_2;
    if (temp_f0_2 < 50.0f) {
        *arg2 = 50.0f;
    }
    if (*arg2 > 1000.0f) {
        *arg2 = 1000.0f;
    }
    *arg2 = 8000.0f / *arg2;
}
