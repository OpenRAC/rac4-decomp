/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 164 / disc 168.
 * Function text: 164 B; native catalogue: 168 B; 15 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Retains unresolved literal-address accesses from the draft; these are not approved data bindings.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_0054C408 nonmatching/pal/game/func_0054C408.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


void *func_00511D30(s32, s32);                      /* extern */

void func_0054C408(void *arg0) {
    s32 temp_a1;
    s32 temp_v0_2;
    s32 var_a0;
    s32 var_v0;
    void *temp_v0;
    void *temp_v0_3;

    var_a0 = 0;
    if (arg0 != NULL) {
        var_v0 = 0 & 0xFF;
        if ((*(s32 *)((s8 *)(arg0) + (0x25CC))) != 0x9B) {
            temp_v0 = (*(void **)((s8 *)(arg0) + (0x2F28)));
            if (temp_v0 != NULL) {
                var_a0 = (*(void **)((s8 *)(temp_v0) + (4))) != NULL;
            }
            goto block_4;
        }
    } else {
block_4:
        var_v0 = var_a0 & 0xFF;
    }
    if ((var_v0 != 0) && ((*(u8 *)((s8 *)(arg0) + (0x266D))) == 0)) {
        temp_a1 = *(s32 *)0x21DBCC;
        temp_v0_2 = (*(s32 *)((s8 *)((*(void **)((s8 *)((*(void **)((s8 *)(arg0) + (0x2F28)))) + (4)))) + (0x50))) ^ temp_a1;
        if (temp_v0_2 != *(s32 *)0x220C30) {
            temp_v0_3 = func_00511D30(temp_v0_2, temp_a1);
            if (temp_v0_3 != NULL) {
                (*(s32 *)((s8 *)(arg0) + (0x1848))) = (s32) (*(s32 *)((s8 *)(temp_v0_3) + (0x2EF0)));
            }
        }
    }
}
