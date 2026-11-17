/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 7/96 (6 words differ).
 * Function text: 96 B; native catalogue: 96 B; 5 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Retains unresolved literal-address accesses from the draft; these are not approved data bindings.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L02_004CDEF8 nonmatching/pal/shared/func_L02_004CDEF8.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


void func_L02_004CDEF8(void *arg0, s32 arg1) {
    void *temp_a1;

    temp_a1 = (*(void **)((s8 *)(arg0) + (0xAC)));
    (*(u16 *)((s8 *)(temp_a1) + (0x84))) = (u16) ((*(u16 *)((s8 *)(temp_a1) + (0x84))) + (s32) ((f32) (s32) ((f32) arg1 * 50.0f) * (*(f32 *)((s8 *)((temp_a1 + (*(s32 *)0x21DFEC * 4))) + (0x70)))));
}
