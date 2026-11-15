/* cflags: -fno-schedule-insns -fno-schedule-insns2 */
/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 56 / disc 52.
 * Function text: 56 B; native catalogue: 52 B; 14 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * The draft s128 placeholder does not establish the native transfer width.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L00_006BED98 nonmatching/pal/shared/func_L00_006BED98.c --diff
 */
#include "common.h"
typedef long long s128;

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


void func_L00_006BED98(void *arg0) {
    (*(s32 *)((s8 *)(arg0) + (0x1B0))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x1780))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x1784))) = 0;
    (*(s128 *)((s8 *)(arg0) + (0x140))) = 0;
    (*(s128 *)((s8 *)(arg0) + (0x130))) = 0;
    (*(s128 *)((s8 *)(arg0) + (0x150))) = 0;
    (*(s128 *)((s8 *)(arg0) + (0x160))) = 0;
    (*(s128 *)((s8 *)(arg0) + (0x170))) = 0;
    (*(s128 *)((s8 *)(arg0) + (0x1A0))) = 0;
    (*(s128 *)((s8 *)(arg0) + (0xC0))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x17A4))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x1B8))) = 0;
}
