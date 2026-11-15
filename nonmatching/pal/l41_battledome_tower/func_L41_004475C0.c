/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 5/72 (3 words differ).
 * Function text: 72 B; native catalogue: 72 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Retains unresolved literal-address accesses from the draft; these are not approved data bindings.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L41_004475C0 nonmatching/pal/l41_battledome_tower/func_L41_004475C0.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


extern void *D_0021E078;

s32 func_L41_004475C0(void *arg0) {
    s32 temp_a1;

    temp_a1 = *(s32 *)0x21E714;
    if ((temp_a1 != 1) || ((*(u8 *)((s8 *)(D_0021E078) + (0x32))) == 0)) {
        return 0;
    }
    if (arg0 != NULL) {
        return (((*(s32 *)((s8 *)(arg0) + (0x2F14))) ^ 1) != 0) ? 0 : temp_a1;
    }
    return 0;
}
