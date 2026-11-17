/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 316 / disc 328.
 * Function text: 316 B; native catalogue: 328 B; 15 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Retains unresolved literal-address accesses from the draft; these are not approved data bindings.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_004C01D0 nonmatching/pal/game/func_004C01D0.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_004C1AF8(s32);                             /* extern */
s32 func_004C1BF8(s32);                             /* extern */
s32 func_004C1CA8(s32);                             /* extern */
s32 func_004C1DA0(s32);                             /* extern */
s32 func_00506BB8();                                /* extern */
extern s32 D_0021EE58;

s32 func_004C01D0(void) {
    s32 temp_v1_2;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s4;
    s32 var_s5;
    s32 var_v0_2;
    s32 var_v1;
    void *temp_v1;
    void *temp_v1_3;
    void *var_v0;

    var_s2 = 0;
    var_s4 = 1;
    var_s5 = -1;
    temp_v1 = (func_00506BB8() * 0x258) + 0x30B358 + 0x1EC;
    if ((*(s32 *)((s8 *)(temp_v1) + (0x50))) > 0) {
        do {
            if (var_s2 < 0) {
                temp_v1_2 = (*(s32 *)((s8 *)(temp_v1) + (0x54)));
                var_v1 = temp_v1_2 * 0x18;
                if (temp_v1_2 < 0) {
                    var_v0 = NULL;
                } else {
                    goto block_6;
                }
            } else {
                var_v1 = var_s2 * 0x18;
block_6:
                var_v0 = (*(s32 *)((s8 *)(temp_v1) + (0x34))) + var_v1;
            }
            temp_v1_3 = (*(void **)((s8 *)(var_v0) + (8)));
            if ((*(u8 *)((s8 *)(temp_v1_3) + (0))) != 0) {

            } else {
                var_s0 = (*(s32 *)((s8 *)(temp_v1_3) + (4)));
                if ((*(s32 *)((s8 *)(temp_v1_3) + (8))) == 0) {
                    if (*(s32 *)0x21EE54 == 0) {
                        var_s0 = ((D_0021EE58 ^ 1) == 0) ? (var_s0 + 0x14) : var_s0;
                    }
                    var_s1 = func_004C1BF8(var_s0);
                    var_v0_2 = func_004C1AF8(var_s0);
                } else {
                    var_s1 = func_004C1DA0(var_s0);
                    var_v0_2 = func_004C1CA8(var_s0);
                }
                if ((var_v0_2 < var_s1) && (var_s4 != 0)) {
                    var_s5 = var_s2;
                    var_s4 = 0;
                }
            }
            var_s2 += 1;
        } while (var_s2 < (*(s32 *)((s8 *)(temp_v1) + (0x50))));
    }
    return var_s5;
}
