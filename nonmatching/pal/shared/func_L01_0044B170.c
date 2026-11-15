/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 39/168 (12 words differ).
 * Function text: 168 B; native catalogue: 168 B; 3 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_0044B170 nonmatching/pal/shared/func_L01_0044B170.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */
void func_L01_0044BBA0(void *object, s32 value, f32 timer);

extern s32 D_0021DE40;

s32 func_L01_0044B170(void *arg0) {
    f32 temp_f1;
    s16 temp_v1;
    s32 temp_hi;
    void *temp_a1;

    temp_a1 = (*(void **)((s8 *)(arg0) + (0xAC)));
    if ((*(s16 *)((s8 *)(temp_a1) + (0xF0))) == 4) {
        temp_v1 = (*(s16 *)((s8 *)(temp_a1) + (0x138)));
        if ((temp_v1 != -1) && ((temp_f1 = (f32) temp_v1, temp_hi = (s32) D_0021DE40 % temp_v1, ((temp_hi < (s32) (temp_f1 * (*(f32 *)((s8 *)(temp_a1) + (0x130))))) != 0)) || (temp_hi >= (s32) (temp_f1 * (*(f32 *)((s8 *)(temp_a1) + (0x134))))))) {
            func_L01_0044BBA0(arg0, (~(*(s16 *)((s8 *)(temp_a1) + (0x13A))) == 0) ? 0 : 5, 0.0f);
            return 1;
        }
        /* Duplicate return node #6. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
