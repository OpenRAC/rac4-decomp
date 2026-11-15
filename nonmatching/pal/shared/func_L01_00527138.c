/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 96 / disc 100.
 * Function text: 96 B; native catalogue: 100 B; 13 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Retains unresolved literal-address accesses from the draft; these are not approved data bindings.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_00527138 nonmatching/pal/shared/func_L01_00527138.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


extern s32 D_00222C84;

s32 func_L01_00527138(void *arg0, void *arg1) {
    void *temp_a0;

    temp_a0 = ((*(s32 *)((s8 *)(arg0) + (0x94))) * 0x470) + 0x230380;
    if ((*(s32 *)0x21DE3C == 0) && ((*(s32 *)((s8 *)((temp_a0 + 0x150)) + (0xFC))) == 0x20) && ((*(s16 *)((s8 *)(arg1) + (0x86))) == 0)) {
        if (D_00222C84 < 2) {
            (*(s32 *)((s8 *)(temp_a0) + (0x468))) = 1;
        }
        return 1;
    }
    return 0;
}
