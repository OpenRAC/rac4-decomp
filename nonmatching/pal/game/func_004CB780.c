/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 58/92 (18 words differ); BYTES 59/92 (18 words differ).
 * Function text: 92 B; native catalogue: 92 B; 15 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Retains unresolved literal-address accesses from the draft; these are not approved data bindings.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_004CB780 nonmatching/pal/game/func_004CB780.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */
s32 func_004A3018(void);

s32 func_004CB780(void) {
    s32 var_v1;

    if (*(u8 *)0x21EE98 != 0) {
        return func_004A3018() == 1;
    }
    var_v1 = 0;
    if (*(s32 *)0x21EE54 == 0) {
        var_v1 = *(s32 *)0x21EE58 == 1;
    }
    return var_v1;
}
