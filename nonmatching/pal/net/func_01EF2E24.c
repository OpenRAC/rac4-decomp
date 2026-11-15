/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 174/616 (58 words differ).
 * Function text: 616 B; native catalogue: 616 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_01EF2E24 nonmatching/pal/net/func_01EF2E24.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */
void **func_01EF2C14(void);
s32 func_01EF2CC4(void);
s32 func_01EF2D88(s32 *p, s32 value);
void **func_01EF6048(void);
void **func_01EF6470(void);
void **func_01EF6A88(void);
void **func_01EF6BE8(void);
void **func_01EF72C8(void);
void **func_01EF7EF0(void);
void **func_01EF8050(void);
void **func_01EF8C34(void);
void **func_01EFB6E0(void);
void **func_01EFCCD4(void);
void **func_01EFD5F4(void);
void **func_01EFDE14(void);
void **func_01EFE6E8(void);
void **func_01EFF990(void);
void **func_01F001EC(void);
void **func_01F0044C(void);
void **func_01F03530(void);
void **func_01F0379C(void);
void **func_01F03C88(void);
void **func_01F04024(void);
void **func_01F04B70(void);
void **func_01F064F4(void);
void **func_01F06654(void);
s32 func_01F07C34(void);
s32 func_01F0A5F0(void);
void **func_01F0BA20(void);
void **func_01F0BB78(void);
void **func_01F0C390(void);

void func_01EF2E24(void) {
    s32 temp_s0;

    temp_s0 = func_01EF2CC4();
    func_01EF2D88((s32 *) temp_s0, func_01EF2C14());
    func_01EF2D88((s32 *) temp_s0, func_01EF6048());
    func_01EF2D88((s32 *) temp_s0, func_01EF6BE8());
    func_01EF2D88((s32 *) temp_s0, func_01EF6470());
    func_01EF2D88((s32 *) temp_s0, func_01EF72C8());
    func_01EF2D88((s32 *) temp_s0, func_01EF7EF0());
    func_01EF2D88((s32 *) temp_s0, func_01F03530());
    func_01EF2D88((s32 *) temp_s0, func_01EFB6E0());
    func_01EF2D88((s32 *) temp_s0, func_01EFCCD4());
    func_01EF2D88((s32 *) temp_s0, func_01EFD5F4());
    func_01EF2D88((s32 *) temp_s0, func_01EFDE14());
    func_01EF2D88((s32 *) temp_s0, func_01EFE6E8());
    func_01EF2D88((s32 *) temp_s0, func_01F001EC());
    func_01EF2D88((s32 *) temp_s0, func_01F03C88());
    func_01EF2D88((s32 *) temp_s0, func_01EFF990());
    func_01EF2D88((s32 *) temp_s0, func_01F06654());
    func_01EF2D88((s32 *) temp_s0, func_01F0044C());
    func_01EF2D88((s32 *) temp_s0, func_01F0379C());
    func_01EF2D88((s32 *) temp_s0, func_01F04024());
    func_01EF2D88((s32 *) temp_s0, func_01F04B70());
    func_01EF2D88((s32 *) temp_s0, func_01F064F4());
    func_01EF2D88((s32 *) temp_s0, func_01F07C34());
    func_01EF2D88((s32 *) temp_s0, func_01EF8050());
    func_01EF2D88((s32 *) temp_s0, func_01EF8C34());
    func_01EF2D88((s32 *) temp_s0, func_01F0A5F0());
    func_01EF2D88((s32 *) temp_s0, func_01F0BA20());
    func_01EF2D88((s32 *) temp_s0, func_01EF6A88());
    func_01EF2D88((s32 *) temp_s0, func_01F0BB78());
    func_01EF2D88((s32 *) temp_s0, func_01F0C390());
}
