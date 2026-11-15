/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 241/400 (72 words differ); BYTES 242/400 (72 words differ); BYTES 243/400 (72 words differ).
 * Function text: 400 B; native catalogue: 400 B; 13 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Retains unresolved literal-address accesses from the draft; these are not approved data bindings.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_0067CF48 nonmatching/pal/shared/func_L01_0067CF48.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


f32 func_L01_0067CEA8(void *);                      /* extern */
extern f32 D_00222C8C;

s32 func_L01_0067CF48(void *arg0) {
    f32 temp_f1;
    f32 var_f0;
    s32 temp_a0_2;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_s1;
    s32 var_v0;
    void *temp_a0;
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x2EF0)));
    var_s1 = 0;
    if ((temp_v0 == NULL) || ((*(u8 *)((s8 *)(temp_v0) + (0x31))) != 0)) {
        var_s1 = 1;
    }
    temp_a0 = (*(void **)((s8 *)(arg0) + (0x2EF0)));
    var_f0 = D_00222C8C;
    if (temp_a0 != NULL) {
        if ((*(u8 *)((s8 *)(arg0) + (0x266D))) != 0) {
            (*(f32 *)((s8 *)(arg0) + (0x2654))) = 0.0f;
        } else {
            (*(f32 *)((s8 *)(arg0) + (0x2654))) = func_L01_0067CEA8(temp_a0);
        }
        var_f0 = *(f32 *)0x222C8C;
    }
    var_a1 = 5;
    if (!(var_f0 >= 0.99f)) {
        var_v0 = 1;
        if (!(*(f32 *)0x222C88 >= 0.99f)) {
            temp_f1 = (*(f32 *)((s8 *)(arg0) + (0x2654)));
            if ((var_s1 == 0) && (temp_f1 > 5.0f)) {
                goto block_12;
            }
            if (var_f0 >= 0.93f) {
                var_a1 = 4;
            }
            if (var_f0 >= 0.98f) {
                var_a1 -= 1;
            }
            temp_a0_2 = *(s32 *)0x21E8A4;
            var_a1_2 = ((temp_a0_2 ^ 1) == 0) ? (var_a1 - 1) : var_a1;
            if (temp_a0_2 == 0) {
                var_a1_2 = ((*(s32 *)0x21E8A8 ^ 1) == 0) ? (var_a1_2 - 2) : var_a1_2;
            }
            if (temp_f1 >= 10.0f) {
                var_a1_2 -= 1;
            }
            if (temp_f1 >= 25.0f) {
                var_a1_2 -= 1;
            }
            var_v0 = (var_a1_2 > 0) ? var_a1_2 : 1;
            /* Duplicate return node #24. Try simplifying control flow for better match */
            return var_v0;
        }
        return var_v0;
    }
block_12:
    return 1;
}
