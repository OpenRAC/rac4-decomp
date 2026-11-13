#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


void func_L02_00485668(void *arg0, s32 arg1) {
    void *temp_a0;

    temp_a0 = (*(void **)((s8 *)((*(void **)((s8 *)(arg0) + (0xAC)))) + (0x2E0)));
    if (arg1 != 0) {
        (*(s32 *)((s8 *)(temp_a0) + (0x2D8))) = (s32) ((*(s32 *)((s8 *)(temp_a0) + (0x2D8))) & 0xDFFFFFFF);
        return;
    }
    (*(s32 *)((s8 *)(temp_a0) + (0x2D8))) = (s32) ((*(s32 *)((s8 *)(temp_a0) + (0x2D8))) | 0x20000000);
}
