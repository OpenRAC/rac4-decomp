/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 25/120 (13 words differ).
 * Function text: 120 B; native catalogue: 120 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_01EF9E18 nonmatching/pal/net/func_01EF9E18.c --diff
 */
#include "common.h"
/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */

void func_01EF9E18(void *arg0)
{
  *((s32 *) (((s8 *) arg0) + 0x114)) = 1;
  *((s32 *) (((s8 *) arg0) + 0x120)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xC8)) = 0;
  *((f32 *) (((s8 *) arg0) + 0x104)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x18))) + 7.0f);
  *((s32 *) (((s8 *) arg0) + 0xD4)) = 0;
  *((f32 *) (((s8 *) arg0) + 0x108)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x1C))) - 2.0f);
  *((s32 *) (((s8 *) arg0) + 0xCC)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xD0)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xF4)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xF8)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xF0)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xFC)) = 1;
  *((s32 *) (((s8 *) arg0) + 0x10C)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xDC)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xE0)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xE4)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xE8)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xEC)) = 0;
  *((s32 *) (((s8 *) arg0) + 0x11C)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xD8)) = 0;
}
