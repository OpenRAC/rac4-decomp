#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


u8 func_L01_005B3880(void *arg0) {
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;

    temp_v1 = (*(void **)((s8 *)(arg0) + (0x24)));
    if ((*(u8 *)((s8 *)(temp_v1) + (0xC))) != 0) {
        temp_v0_2 = (*(void **)((s8 *)((*(void **)((s8 *)(((u32)temp_v1 + ((u32)(*(u8 *)((s8 *)(arg0) + (0x54))) << 2))) + (0x48)))) + (0x18)));
        if (temp_v0_2 != NULL) {
            temp_v0 = (*(void **)((s8 *)(temp_v0_2) + (4)));
            if (temp_v0 != NULL) {
                return (*(u8 *)((s8 *)(temp_v0) + (5)));
            }
        }
    }
    return 0U;
}
