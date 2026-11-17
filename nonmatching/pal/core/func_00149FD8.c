/* cflags: @ee29-01 -O2 -G0 -Wa,-G0 */
/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 31/116 (20 words differ).
 * Function text: 116 B; native catalogue: 116 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_00149FD8 nonmatching/pal/core/func_00149FD8.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


void func_00149FD8(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f4;
    void *temp_a1;

    temp_a1 = arg1 + (arg2 * 8);
    temp_f4 = (*(f32 *)((s8 *)(temp_a1) + (0)));
    temp_f2 = (*(f32 *)((s8 *)(temp_a1) + (4)));
    temp_f1 = 1.0f / ((temp_f4 * temp_f4) + (temp_f2 * temp_f2));
    (*(f32 *)((s8 *)(arg3) + (0))) = (f32) (temp_f1 * (((*(f32 *)((s8 *)(arg0) + (0))) * temp_f4) - ((*(f32 *)((s8 *)(arg0) + (4))) * temp_f2)));
    (*(f32 *)((s8 *)(arg3) + (4))) = (f32) (temp_f1 * (((*(f32 *)((s8 *)(arg0) + (4))) * (*(f32 *)((s8 *)(temp_a1) + (0)))) + ((*(f32 *)((s8 *)(arg0) + (0))) * (*(f32 *)((s8 *)(temp_a1) + (4))))));
}
