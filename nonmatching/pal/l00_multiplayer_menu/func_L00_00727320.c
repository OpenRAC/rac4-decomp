/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 140 / disc 144.
 * Function text: 140 B; native catalogue: 144 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Retains unresolved literal-address accesses from the draft; these are not approved data bindings.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L00_00727320 nonmatching/pal/l00_multiplayer_menu/func_L00_00727320.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_L00_00727320(void) {
    void *temp_a1;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *var_v0;
    void *var_v0_2;

    temp_a1 = *(void **)0x220DD4;
    temp_v1 = (*(void **)((s8 *)(*(void **)0x2234A4) + (0x3C)));
    if ((*(u8 *)((s8 *)(temp_v1) + (0x30))) != 0) {
        temp_v1_2 = (*(void **)((s8 *)(temp_a1) + (0x108)));
        var_v0 = NULL;
        if (temp_v1_2 != NULL) {
            var_v0 = (((*(u8 *)((s8 *)(temp_v1_2) + (0xA8))) ^ 1) != 0) ? NULL : temp_v1_2;
        }
        if (var_v0 == NULL) {
            (*(s32 *)((s8 *)(temp_a1) + (0x11C))) = 8;
        }
        /* Duplicate return node #5. Try simplifying control flow for better match */
        return 1;
    }
    if ((*(s32 *)((s8 *)(temp_v1) + (0))) >= 0) {
        temp_v1_3 = (*(void **)((s8 *)(temp_a1) + (0x108)));
        var_v0_2 = NULL;
        if (temp_v1_3 != NULL) {
            var_v0_2 = (((*(u8 *)((s8 *)(temp_v1_3) + (0xA8))) ^ 1) != 0) ? NULL : temp_v1_3;
        }
        if (var_v0_2 == NULL) {
            (*(s32 *)((s8 *)(temp_a1) + (0x11C))) = 5;
        }
        return 1;
    }
    return 0;
}
