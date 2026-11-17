/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 2/80 (2 words differ); MATCH.
 * Function text: 80 B; native catalogue: 80 B; 11 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Retains unresolved literal-address accesses from the draft; these are not approved data bindings.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L02_004050F8 nonmatching/pal/shared/func_L02_004050F8.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_L02_004050F8(void *arg0) {
    void *temp_a0;

    temp_a0 = (*(void **)((s8 *)(arg0) + (0xAC)));
    if ((*(s32 *)0x21E774 == 0) && (*(s32 *)0x21E778 == 1) && ((*(s32 *)((s8 *)(temp_a0) + (0x58))) == 0x1F7)) {
        return 1;
    }
    return (*(s32 *)((s8 *)(temp_a0) + (4))) >= (*(s32 *)((s8 *)(temp_a0) + (0x54)));
}
