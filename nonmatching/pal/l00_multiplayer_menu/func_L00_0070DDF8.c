/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 200 / disc 184.
 * Function text: 200 B; native catalogue: 184 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L00_0070DDF8 nonmatching/pal/l00_multiplayer_menu/func_L00_0070DDF8.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


void *func_L00_0070D7D8(void *);                    /* extern */
extern void *D_00220ABC;
extern void *D_00220AC0;
extern void *D_00220AC4;

void func_L00_0070DDF8(void *arg0, s32 arg1) {
    s32 var_s3;
    void *temp_s4;
    void *var_a0;
    void *var_s0;
    void *var_s1;

    var_a0 = arg0;
    var_s0 = NULL;
    var_s1 = NULL;
    var_s3 = 0;
    temp_s4 = var_a0;
    do {
        var_a0 = func_L00_0070D7D8(var_a0);
        if (var_a0 == NULL) {
            var_s3 = 1;
        } else if (((*(s32 *)((s8 *)(var_a0) + (0))) != temp_s4) || ((arg1 != -1) && (arg1 != (*(s32 *)((s8 *)(var_a0) + (8)))))) {
            D_00220ABC = (*(void **)((s8 *)(D_00220ABC) + (0x19C)));
            (*(s32 *)((s8 *)(var_a0) + (0x19C))) = 0;
            if (var_s0 != NULL) {
                (*(void **)((s8 *)(var_s0) + (0x19C))) = var_a0;
            }
            var_s0 = var_a0;
            var_s1 = (var_s1 == NULL) ? var_s0 : var_s1;
        }
    } while (var_s3 == 0);
    D_00220AC0 = var_s1;
    D_00220AC4 = var_s0;
}
