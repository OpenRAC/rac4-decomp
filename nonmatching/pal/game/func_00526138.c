/* Not matching yet: PAL WIP; main .text 0x00526138, 252B. Not part of the build. */
/*
 * comparison is always true due to limited range of data type
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: cd0292e6100941f3a32ee58869b952324fc2647e512c993ddd482acf3c446e55
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00526138 nonmatching/pal/game/func_00526138.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


f32 func_00525D80(void *, void *);                          /* extern */

f32 func_00526138(void *arg0, void *arg1, void *arg2, s32 *arg3, f32 fparg0) {
    f32 temp_f1;
    f32 var_f0;
    s32 temp_f3;
    s32 temp_v0_2;
    u8 temp_v0;

    temp_v0 = (*(u8 *)((s8 *)(arg0) + (0x2659)));
    if (temp_v0 != 0) {
        if (((s32) temp_v0 >= 0) && ((s32) temp_v0 < 3)) {
            temp_v0_2 = (s32) (func_00525D80(arg0, arg2) / fparg0);
            if (arg3 != NULL) {
                *arg3 = temp_v0_2;
            }
            return (*(f32 *)((s8 *)(arg1) + (8))) + ((*(f32 *)((s8 *)(arg2) + (8))) * 0.5f);
        }
        var_f0 = 0.0f;
        /* Duplicate return node #10. Try simplifying control flow for better match */
        return var_f0;
    }
    temp_f1 = (*(f32 *)((s8 *)(arg2) + (8)));
    temp_f3 = (s32) (temp_f1 / fparg0);
    var_f0 = ((*(f32 *)((s8 *)(arg1) + (8))) + (temp_f1 * (f32) temp_f3)) - ((f32) ((s32) ((temp_f3 * temp_f3) + temp_f3) >> 1) * fparg0);
    if (arg3 != NULL) {
        *arg3 = temp_f3;
        return var_f0;
    }
    return var_f0;
}
