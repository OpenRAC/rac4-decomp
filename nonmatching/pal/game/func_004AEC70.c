/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 112 / disc 116.
 * Function text: 112 B; native catalogue: 116 B; 15 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Retains unresolved literal-address accesses from the draft; these are not approved data bindings.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_004AEC70 nonmatching/pal/game/func_004AEC70.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */
s32 func_0011D920(s8 *arg0, s8 *arg1, ...);

void func_004AEC70(s32 arg0, s32 arg1) {
    s8 temp_v0;
    void *temp_s0;

    temp_s0 = (arg0 * 0x50) + 0x3092A0;
    if (arg1 != (*(s32 *)((s8 *)(temp_s0) + (0x4C)))) {
        (*(s32 *)((s8 *)(temp_s0) + (0x4C))) = arg1;
        temp_v0 = arg1 >= 2;
        (*(s8 *)((s8 *)(temp_s0) + (0x3D))) = temp_v0;
        if (temp_v0 != 0) {
            func_0011D920(temp_s0 + 0x48, (s8 *)0x21F7B0, arg1);
            (*(f32 *)((s8 *)(temp_s0) + (0x44))) = 1.0f;
        }
    }
}
