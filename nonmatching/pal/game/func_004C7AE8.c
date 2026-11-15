/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 264 / disc 272.
 * Function text: 264 B; native catalogue: 272 B; 15 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_004C7AE8 nonmatching/pal/game/func_004C7AE8.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_00506BB8();                                /* extern */
void *func_0054BF00(s32);                           /* extern */
s32 func_0054C070(s32, s32);                        /* extern */

s32 func_004C7AE8(void) {
    s32 temp_v1;
    s32 var_s1;
    s32 var_s4;
    s32 var_v1;
    void *temp_s0;
    void *temp_s2;
    void *temp_s3;
    void *var_v0;

    var_s1 = 0;
    var_s4 = -1;
    temp_s3 = (func_00506BB8() * 0xB30) + 0x30B9D8;
    if ((*(s32 *)((s8 *)(temp_s3) + (0xB04))) > 0) {
        do {
            temp_s2 = temp_s3 + 0xAB4;
            if (var_s4 == -1) {
                if (var_s1 < 0) {
                    temp_v1 = (*(s32 *)((s8 *)(temp_s2) + (0x54)));
                    var_v1 = temp_v1 * 0x18;
                    if (temp_v1 < 0) {
                        var_v0 = NULL;
                    } else {
                        goto block_7;
                    }
                } else {
                    var_v1 = var_s1 * 0x18;
block_7:
                    var_v0 = (*(s32 *)((s8 *)(temp_s2) + (0x34))) + var_v1;
                }
                temp_s0 = (*(void **)((s8 *)(var_v0) + (8)));
                if (((*(s32 *)((s8 *)(temp_s0) + (8))) != 1) && ((*(s32 *)((s8 *)(func_0054BF00(func_0054C070((*(s32 *)((s8 *)(temp_s3) + (0xB2C))), (*(s32 *)((s8 *)(temp_s0) + (4)))))) + (0x14))) != 0)) {
                    var_s4 = ((*(u8 *)((s8 *)(temp_s0) + (2))) != 0) ? var_s1 : var_s4;
                }
            }
            var_s1 += 1;
        } while (var_s1 < (*(s32 *)((s8 *)(temp_s2) + (0x50))));
    }
    return var_s4;
}
