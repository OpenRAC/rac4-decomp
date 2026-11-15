/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 16/44 (4 words differ).
 * Function text: 44 B; native catalogue: 44 B; 5 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L05_00468540 nonmatching/pal/shared/func_L05_00468540.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


f32 func_L05_00468540(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0xAC)));
    return (*(f32 *)((s8 *)(temp_v0) + (0x17C))) + ((*(f32 *)((s8 *)(temp_v0) + (0x1E4))) * (1.0f - __builtin_fabsf((*(f32 *)((s8 *)(temp_v0) + (0x1FC))))));
}
