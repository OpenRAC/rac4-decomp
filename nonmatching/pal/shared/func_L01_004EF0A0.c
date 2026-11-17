/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 9/52 (3 words differ).
 * Function text: 52 B; native catalogue: 52 B; 12 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_004EF0A0 nonmatching/pal/shared/func_L01_004EF0A0.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


f32 func_L01_004EF0A0(void *arg0) {
    void *temp_v1;

    temp_v1 = (*(void **)((s8 *)((*(void **)((s8 *)(arg0) + (0xAC)))) + (0x2F4)));
    if (temp_v1 != NULL) {
        return (*(f32 *)((s8 *)(temp_v1) + (0x18))) - (*(f32 *)((s8 *)((*(void **)((s8 *)(temp_v1) + (0xAC)))) + (0x18)));
    }
    return (*(f32 *)((s8 *)(arg0) + (0x18))) - 0.5f;
}
