/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 360 / disc 364.
 * Function text: 360 B; native catalogue: 364 B; 13 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_00427B10 nonmatching/pal/shared/func_L01_00427B10.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_00540958(void *);                          /* extern */
s32 func_0054A308(s32, s32);                        /* extern */
s32 func_L01_004279B0(void *);                      /* extern */

s32 func_L01_00427B10(void *arg0, void *arg1) {
    s32 temp_v1;
    s32 var_s0;
    s32 var_s3;
    s32 var_v1;
    void *temp_s2;
    void *temp_v0;

    var_s3 = 0;
    temp_v0 = (*(void **)((s8 *)(arg0) + (0x2EFC)));
    temp_s2 = (*(void **)((s8 *)(arg1) + (0xAC)));
    if (temp_v0 != NULL) {
        var_v1 = 0;
        if ((*(u8 *)((s8 *)(temp_v0) + (0x27B))) != 0) {
            var_v1 = (*(s32 *)((s8 *)(arg0) + (0x25CC))) == 0x31;
        }
    } else {
        var_v1 = 0;
    }
    if (!(var_v1 & 0xFF) && ((*(s32 *)((s8 *)(arg0) + (0x25D4))) != 0x14) && !((*(f32 *)((s8 *)(arg0) + (0x2E20))) <= 0.0f)) {
        temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x25CC)));
        if ((temp_v1 != 0x39) && (temp_v1 != 0x68) && (temp_v1 != 0x6A) && (temp_v1 != 0x76) && (temp_v1 != 0x7A) && (temp_v1 != 0x7B) && (temp_v1 != 0x7E) && (temp_v1 != 0x7F) && (temp_v1 != 0x94) && (temp_v1 != 0x99) && (func_00540958(arg0) == 0) && ((*(s32 *)((s8 *)(arg0) + (0x2EF4))) == 0)) {
            var_s3 = func_L01_004279B0(arg1) == 0;
        }
    }
    var_s0 = 1;
    if (var_s3 != 0) {
loop_22:
        if (((s32) (*(s32 *)((s8 *)(temp_s2) + (0xC))) >> var_s0) & 1) {
            if (func_0054A308((*(s32 *)((s8 *)(arg0) + (0x26E4))), var_s0) & 0xFF) {
                goto block_26;
            }
            return 1;
        }
block_26:
        var_s0 += 1;
        if (var_s0 >= 0x14) {
            goto block_27;
        }
        goto loop_22;
    }
block_27:
    return 0;
}
