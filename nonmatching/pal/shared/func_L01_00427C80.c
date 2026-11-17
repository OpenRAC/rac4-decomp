/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 86/308 (41 words differ).
 * Function text: 308 B; native catalogue: 308 B; 13 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_00427C80 nonmatching/pal/shared/func_L01_00427C80.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_00540958();                                /* extern */
s32 func_L01_004279B0(s32);                         /* extern */

s32 func_L01_00427C80(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    s32 var_s3;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    void *temp_v0;

    var_s3 = 0;
    if ((*(s32 *)((s8 *)(arg0) + (0x25D4))) != 0x14) {
        var_v0 = 0;
        if (!((*(f32 *)((s8 *)(arg0) + (0x2E20))) <= 0.0f)) {
            temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x25CC)));
            if ((temp_v1 != 0x39) && (temp_v1 != 0x68) && (temp_v1 != 0x6A) && (temp_v1 != 0x76) && (temp_v1 != 0x7A) && (temp_v1 != 0x7B) && (temp_v1 != 0x7E) && (temp_v1 != 0x7F) && (temp_v1 != 0x94)) {
                var_v0 = 0;
                if (temp_v1 != 0x99) {
                    var_v0 = 0;
                    if (func_00540958() == 0) {
                        temp_v0 = (*(void **)((s8 *)(arg0) + (0x2EFC)));
                        var_v1 = 0;
                        if (temp_v0 != NULL) {
                            var_v0_2 = 0 & 0xFF;
                            if ((*(u8 *)((s8 *)(temp_v0) + (0x27B))) != 0) {
                                var_v1 = (*(s32 *)((s8 *)(arg0) + (0x25CC))) == 0x31;
                                goto block_16;
                            }
                        } else {
block_16:
                            var_v0_2 = var_v1 & 0xFF;
                        }
                        var_v0 = 0;
                        if (var_v0_2 == 0) {
                            var_v0 = 0;
                            if (((*(s32 *)((s8 *)(arg0) + (0x2EF4))) == 0) && ((arg2 == 0) || (var_v0 = 0, (func_L01_004279B0(arg1) == 0)))) {
                                var_s3 = 1;
                                goto block_22;
                            }
                        }
                    }
                }
            } else {
                goto block_22;
            }
        }
    } else {
block_22:
        var_v0 = var_s3;
    }
    return var_v0;
}
