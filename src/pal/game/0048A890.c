#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


extern s32 D_0021EE54;

void func_0048A890(s32 arg0, s64 arg1) {
    s16 temp_v1;
    s8 *temp_a1;

    temp_a1 = (s8 *)(u32)arg1;
    if (temp_a1 != 0) {
        (*(s32 *)((s8 *)(temp_a1) + (0))) = arg0;
        if (arg0 != 0) {
            temp_v1 = (*(s16 *)((s8 *)(temp_a1) + (0xA)));
            if (temp_v1 == 1) {
                if (D_0021EE54 == temp_v1) {
                    (*(s16 *)((s8 *)(temp_a1) + (0xA))) = 4;
                    return;
                }
                (*(s16 *)((s8 *)(temp_a1) + (0xA))) = 8;
            }
        } else {
            (*(s16 *)((s8 *)(temp_a1) + (0xA))) = 0;
        }
    }
}
