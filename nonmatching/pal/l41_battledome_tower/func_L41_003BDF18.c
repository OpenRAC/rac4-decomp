/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 3/56 (3 words differ).
 * Function text: 56 B; native catalogue: 56 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L41_003BDF18 nonmatching/pal/l41_battledome_tower/func_L41_003BDF18.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


f32 func_L41_003BDF18(void *arg0, void *arg1, f32 fparg0) {
    f32 var_f0;
    s32 var_v0;

    var_v0 = 1;
    if (!((*(f32 *)((s8 *)((*(void **)((s8 *)(arg1) + (0x20)))) + (0x18))) < (*(f32 *)((s8 *)(arg0) + (0x18))))) {
        var_v0 = 0;
    }
    var_f0 = 0.0f;
    if (!(var_v0 & 0xFF)) {
        var_f0 = fparg0;
    }
    return var_f0;
}
