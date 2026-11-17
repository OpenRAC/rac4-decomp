/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 4/52 (1 words differ).
 * Function text: 52 B; native catalogue: 52 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_004E5630 nonmatching/pal/l01_dreadzone_station/func_L01_004E5630.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */
void func_L01_004E55E0(void *object);

s32 func_L01_004E5630(void *arg0) {
    void *temp_s0;

    temp_s0 = (*(void **)((s8 *)(arg0) + (0xAC)));
    func_L01_004E55E0(arg0);
    return ~(*(s32 *)((s8 *)(temp_s0) + (0x334))) < 0;
}
