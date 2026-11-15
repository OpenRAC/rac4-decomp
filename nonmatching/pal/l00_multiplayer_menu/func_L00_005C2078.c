/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 424 / disc 428.
 * Function text: 424 B; native catalogue: 428 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L00_005C2078 nonmatching/pal/l00_multiplayer_menu/func_L00_005C2078.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


void func_L00_005C2078(void *arg0, void *arg1) {
    s32 temp_a1;
    u32 temp_a4;

    temp_a1 = ((*(u8 *)((s8 *)(arg0) + (0))) << 8) | (*(u8 *)((s8 *)(arg0) + (1)));
    temp_a4 = temp_a1 & 0xFFFF;
    if (temp_a4 < 0x80U) {
        (*(s8 *)((s8 *)(arg1) + (1))) = 0;
        (*(s8 *)((s8 *)(arg1) + (0))) = (s8) (temp_a1 & 0x7F);
        return;
    }
    if ((u32) (temp_a4 - 0x80) < 0x780U) {
        (*(s8 *)((s8 *)(arg1) + (1))) = (s8) ((temp_a1 & 0x3F) | 0x80);
        (*(s8 *)((s8 *)(arg1) + (0))) = (s8) (((temp_a4 >> 6) & 0x1F) | 0xC0);
        (*(s8 *)((s8 *)(arg1) + (2))) = 0;
        return;
    }
    if ((u32) (temp_a4 - 0x800) <= 0xF7FFU) {
        (*(s8 *)((s8 *)(arg1) + (0))) = (s8) ((temp_a4 >> 0xC) | 0xE0);
        (*(s8 *)((s8 *)(arg1) + (1))) = (s8) (((temp_a4 >> 6) & 0x3F) | 0x80);
        (*(s8 *)((s8 *)(arg1) + (2))) = (s8) ((temp_a1 & 0x3F) | 0x80);
        (*(s8 *)((s8 *)(arg1) + (3))) = 0;
        return;
    }
    if ((u32) (temp_a4 + 0xFFFF0000) <= 0x1EFFFFU) {
        (*(s8 *)((s8 *)(arg1) + (0))) = 0xF0;
        (*(s8 *)((s8 *)(arg1) + (1))) = (s8) ((temp_a4 >> 0xC) | 0x80);
        (*(s8 *)((s8 *)(arg1) + (2))) = (s8) (((temp_a4 >> 6) & 0x3F) | 0x80);
        (*(s8 *)((s8 *)(arg1) + (3))) = (s8) ((temp_a1 & 0x3F) | 0x80);
        (*(s8 *)((s8 *)(arg1) + (4))) = 0;
        return;
    }
    if ((u32) (temp_a4 + 0xFFE00000) <= 0x03DFFFFFU) {
        (*(s8 *)((s8 *)(arg1) + (0))) = 0xF8;
        (*(s8 *)((s8 *)(arg1) + (1))) = 0x80;
        (*(s8 *)((s8 *)(arg1) + (2))) = (s8) ((temp_a4 >> 0xC) | 0x80);
        (*(s8 *)((s8 *)(arg1) + (3))) = (s8) (((temp_a4 >> 6) & 0x3F) | 0x80);
        (*(s8 *)((s8 *)(arg1) + (4))) = (s8) ((temp_a1 & 0x3F) | 0x80);
        (*(s8 *)((s8 *)(arg1) + (5))) = 0;
        return;
    }
    if ((u32) (temp_a4 + 0xFC000000) <= 0x7BFFFFFFU) {
        (*(s8 *)((s8 *)(arg1) + (0))) = 0xFC;
        (*(s8 *)((s8 *)(arg1) + (1))) = 0x80;
        (*(s8 *)((s8 *)(arg1) + (2))) = 0x80;
        (*(s8 *)((s8 *)(arg1) + (3))) = (s8) ((temp_a4 >> 0xC) | 0x80);
        (*(s8 *)((s8 *)(arg1) + (4))) = (s8) (((temp_a4 >> 6) & 0x3F) | 0x80);
        (*(s8 *)((s8 *)(arg1) + (5))) = (s8) ((temp_a1 & 0x3F) | 0x80);
        (*(s8 *)((s8 *)(arg1) + (6))) = 0;
    }
}
