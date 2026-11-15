/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 21/120 (8 words differ).
 * Function text: 120 B; native catalogue: 120 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L00_0074C440 nonmatching/pal/l00_multiplayer_menu/func_L00_0074C440.c --diff
 */
#include "common.h"
/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */

void func_L00_0074C440(void *arg0)
{
  s32 *var_a3;
  s32 temp_v1;
  u32 var_a5;
  u8 *var_a2;
  var_a5 = 0;
  var_a2 = arg0 + 0x294;
  var_a3 = arg0 + 0x264;
  do
  {
    temp_v1 = *var_a3;
    var_a5 += 1;
    var_a3 += 1;
    if ((((~temp_v1) != 0) && ((*((s32 *) (((s8 *) ((temp_v1 * 0x5C0) + 0x1EE680)) + 0x1A8))) & 0x40)) && ((temp_v1 != 0) || ((*((u8 *) (((s8 *) arg0) + 0x298))) != 0)))
    {
      *var_a2 ^= 1;
    }
    var_a2 += 1;
  }
  while (var_a5 < 4U);
}
