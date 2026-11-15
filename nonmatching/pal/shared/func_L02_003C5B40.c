/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 160 / disc 176.
 * Function text: 160 B; native catalogue: 176 B; 8 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L02_003C5B40 nonmatching/pal/shared/func_L02_003C5B40.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


f32 func_L02_003C5B40(f32 fparg0) {
    f32 temp_f12;
    f32 temp_f12_2;

    if (!(fparg0 < 0.0f)) {
        temp_f12_2 = fparg0 + 3.1415927f;
        return (temp_f12_2 - ((f32) (s32) (temp_f12_2 / 6.2831855f) * 6.2831855f)) - 3.1415927f;
    }
    temp_f12 = 3.1415927f - fparg0;
    return 3.1415927f - (temp_f12 - ((f32) (s32) (temp_f12 / 6.2831855f) * 6.2831855f));
}
