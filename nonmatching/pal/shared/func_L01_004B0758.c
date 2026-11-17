/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 144 / disc 152.
 * Function text: 144 B; native catalogue: 152 B; 7 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Retains unresolved literal-address accesses from the draft; these are not approved data bindings.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_004B0758 nonmatching/pal/shared/func_L01_004B0758.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_L01_004B0758(void *arg0) {
    s32 temp_a2;
    s32 temp_f1;
    s32 temp_v1;
    s32 var_v0;
    void *temp_a0;

    temp_a0 = (*(void **)((s8 *)(arg0) + (0xAC)));
    temp_v1 = (*(s32 *)((s8 *)(temp_a0) + (0xA0)));
    temp_a2 = (*(s32 *)((s8 *)(temp_a0) + (0xA8)));
    temp_f1 = (s32) ((((f32) temp_v1 * (f32) (*(s32 *)((s8 *)((temp_a0 + (*(s32 *)0x21DFEC * 4))) + (0x8C)))) / 100.0f) + 0.5f);
    if ((temp_a2 >= temp_v1) || (((var_v0 = temp_a2 < temp_f1, ((*(s32 *)((s8 *)(temp_a0) + (0xB0))) != 0)) || (var_v0 = temp_a2 < temp_f1, ((*(s32 *)((s8 *)(temp_a0) + (0xAC))) <= 0))) && (var_v0 == 0))) {
        return 1;
    }
    return 0;
}
