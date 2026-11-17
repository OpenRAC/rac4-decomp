/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 124 / disc 120.
 * Function text: 124 B; native catalogue: 120 B; 14 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Retains unresolved literal-address accesses from the draft; these are not approved data bindings.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L00_006969F0 nonmatching/pal/shared/func_L00_006969F0.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


void *func_00476F70();                              /* extern */
extern f32 D_002203F8;

void func_L00_006969F0(void) {
    s32 temp_f1;
    void *temp_v0;

    if (*(s32 *)0x21E734 == 0) {
        if (*(s32 *)0x21E738 == 1) {
            temp_v0 = func_00476F70();
            if (temp_v0 != NULL) {
                temp_f1 = (s32) ((f32) (*(s32 *)((s8 *)(temp_v0) + (4))) * D_002203F8);
                (*(s32 *)((s8 *)(temp_v0) + (4))) = (s32) (s16) temp_f1;
                (*(f32 *)((s8 *)(temp_v0) + (0))) = (f32) (s16) temp_f1;
            }
        }
    }
}
