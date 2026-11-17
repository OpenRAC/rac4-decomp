/* cflags: @ee29-01 -O2 -G0 -Wa,-G0 */
/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 72 / disc 64.
 * Function text: 72 B; native catalogue: 64 B; 15 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_00477FA8 nonmatching/pal/game/func_00477FA8.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


f32 func_00477FA8(f32 fparg0) {
    f32 temp_f12;

    temp_f12 = (fparg0 + 3.1415927f) / 6.2831855f;
    return ((temp_f12 - (f32) (s32) temp_f12) * 6.2831855f) - 3.1415927f;
}
