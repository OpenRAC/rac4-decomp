/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 360 / disc 364.
 * Function text: 360 B; native catalogue: 364 B; 14 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Retains unresolved literal-address accesses from the draft; these are not approved data bindings.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L00_006F2158 nonmatching/pal/shared/func_L00_006F2158.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


void func_L00_006F2158(void *arg0) {
    s32 temp_v0;
    void *temp_a0;
    void *temp_v1;

    if ((*(s8 *)((s8 *)(*(void **)0x21E078) + (0x20))) != 0) {
        (*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x26E4)))) + (0xABA))) = 1;
        (*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x26E4)))) + (0xAFE))) = 1;
        (*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x26E4)))) + (0xB42))) = 1;
        (*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x26E4)))) + (0xB86))) = 1;
        (*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x26E4)))) + (0xBCA))) = 1;
        (*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x26E4)))) + (0xC0E))) = 1;
        (*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x26E4)))) + (0xC52))) = 1;
        (*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x26E4)))) + (0xE2E))) = 1;
    } else {
        temp_a0 = (*(void **)((s8 *)(arg0) + (0x26E4)));
        temp_v1 = (*(void **)((s8 *)((*(void **)((s8 *)(arg0) + (0x2F28)))) + (4)));
        if ((*(u16 *)((s8 *)(temp_v1) + (0xB8))) & 4) {
            (*(s16 *)((s8 *)(temp_a0) + (0xABA))) = 1;
        } else {
            (*(s16 *)((s8 *)(temp_a0) + (0xABA))) = 0;
        }
        if ((*(u16 *)((s8 *)(temp_v1) + (0xB8))) & 8) {
            (*(s16 *)((s8 *)(temp_a0) + (0xAFE))) = 1;
        } else {
            (*(s16 *)((s8 *)(temp_a0) + (0xAFE))) = 0;
        }
        if ((*(u16 *)((s8 *)(temp_v1) + (0xB8))) & 0x10) {
            (*(s16 *)((s8 *)(temp_a0) + (0xB42))) = 1;
        } else {
            (*(s16 *)((s8 *)(temp_a0) + (0xB42))) = 0;
        }
        if ((*(u16 *)((s8 *)(temp_v1) + (0xB8))) & 0x20) {
            (*(s16 *)((s8 *)(temp_a0) + (0xB86))) = 1;
        } else {
            (*(s16 *)((s8 *)(temp_a0) + (0xB86))) = 0;
        }
        if ((*(u16 *)((s8 *)(temp_v1) + (0xB8))) & 0x40) {
            (*(s16 *)((s8 *)(temp_a0) + (0xBCA))) = 1;
        } else {
            (*(s16 *)((s8 *)(temp_a0) + (0xBCA))) = 0;
        }
        if ((*(u16 *)((s8 *)(temp_v1) + (0xB8))) & 0x80) {
            (*(s16 *)((s8 *)(temp_a0) + (0xC0E))) = 1;
        } else {
            (*(s16 *)((s8 *)(temp_a0) + (0xC0E))) = 0;
        }
        if ((*(u16 *)((s8 *)(temp_v1) + (0xB8))) & 0x100) {
            (*(s16 *)((s8 *)(temp_a0) + (0xC52))) = 1;
        } else {
            (*(s16 *)((s8 *)(temp_a0) + (0xC52))) = 0;
        }
        if ((*(u16 *)((s8 *)(temp_v1) + (0xB8))) & 0x8000) {
            (*(s16 *)((s8 *)(temp_a0) + (0xE2E))) = 1;
        } else {
            (*(s16 *)((s8 *)(temp_a0) + (0xE2E))) = 0;
        }
    }
    temp_v0 = (*(s32 *)((s8 *)((*(void **)((s8 *)((*(void **)((s8 *)(arg0) + (0x2F28)))) + (4)))) + (0x48)));
    if (temp_v0 != (*(s32 *)((s8 *)(arg0) + (0x2318)))) {
        (*(s32 *)((s8 *)(arg0) + (0x2674))) = temp_v0;
    }
}
