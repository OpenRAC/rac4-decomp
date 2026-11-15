/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 14/80 (4 words differ).
 * Function text: 80 B; native catalogue: 80 B; 15 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_0048A890 nonmatching/pal/game/func_0048A890.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


extern s32 D_0021EE54;

void func_0048A890(s32 arg0, s64 arg1) {
    s16 temp_v1;
    s64 temp_a1;

    temp_a1 = (s64) (arg1 << 0x20) >> 0x20;
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
