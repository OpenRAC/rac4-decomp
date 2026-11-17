/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 124 / disc 112.
 * Function text: 124 B; native catalogue: 112 B; 12 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Retains unresolved literal-address accesses from the draft; these are not approved data bindings.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_003CC778 nonmatching/pal/shared/func_L01_003CC778.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


extern s8 D_0021EC70;
extern s8 D_00220C10;
extern s8 D_00220C11;

void func_L01_003CC778(void) {
    if ((*(s32 *)0x21EC58 < 8) || ((*(u8 *)((s8 *)(((((s32) (*(s32 *)0x21DE98 - 1) % 20) * 0x304) + 0x1F8878)) + (0x69))) == 0)) {
        D_00220C10 = 0;
        D_00220C11 = 0;
        D_0021EC70 = 0;
        return;
    }
    *(s8 *)0x21EC70 = 0;
    D_00220C11 = 1;
    D_00220C10 = 1;
}
