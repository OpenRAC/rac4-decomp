/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 101/236 (30 words differ).
 * Function text: 236 B; native catalogue: 236 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Retains unresolved literal-address accesses from the draft; these are not approved data bindings.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_0050E110 nonmatching/pal/l01_dreadzone_station/func_L01_0050E110.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


void *func_0047DE20();                              /* extern */
extern s32 D_0021DE40;

void func_L01_0050E110(void *arg0) {
    s32 temp_v0;
    s32 var_a0;
    s32 var_a2;
    void *temp_a1;
    void *temp_s0;

    temp_s0 = (*(void **)((s8 *)(arg0) + (0xAC)));
    temp_a1 = func_0047DE20();
    if ((*(s32 *)0x21E8A4 == 0) && (*(s32 *)0x21E8A8 == 0) && ((*(u8 *)((s8 *)(temp_a1) + (3))) != 0) && (*(s16 *)0x24AE4C == 0)) {
        temp_v0 = (*(s32 *)((s8 *)(temp_s0) + (0x820))) + 1;
        (*(s32 *)((s8 *)(temp_s0) + (0x820))) = temp_v0;
        if (temp_v0 & 1) {
            var_a2 = -1;
            if ((*(s32 *)((s8 *)(temp_a1) + (0x1E0))) & 1) {
                var_a2 = 1;
            } else if (!((*(s32 *)((s8 *)(temp_a1) + (0x1E4))) & 1)) {
                if ((*(u8 *)((s8 *)(temp_a1) + (3))) != 0) {
                    var_a2 = (*(s32 *)((s8 *)(temp_s0) + (0x830))) ^ 1;
                }
            } else {
                var_a2 = 0;
            }
            if (var_a2 == 0) {
                var_a0 = 0x289E;
            } else {
                var_a0 = ((var_a2 ^ 1) == 0) ? 0x28A3 : -1;
            }
            if (var_a0 >= 0) {
                (*(s32 *)((s8 *)(temp_a1) + (0x18))) = (s32) D_0021DE40;
                (*(s32 *)((s8 *)(temp_s0) + (0x830))) = var_a2;
                (*(s32 *)((s8 *)(temp_s0) + (0x810))) = (s32) *(s32 *)0x21DE40;
            }
        }
    }
}
