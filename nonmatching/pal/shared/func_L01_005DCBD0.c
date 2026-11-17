/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 10/44 (5 words differ); BYTES 9/44 (5 words differ).
 * Function text: 44 B; native catalogue: 44 B; 13 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_005DCBD0 nonmatching/pal/shared/func_L01_005DCBD0.c --diff
 */
#include "common.h"
/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */

s32 func_L01_005DCBD0(u32 arg0)
{
  s32 rac4_value_0;
  if (arg0 >= 4U)
  {
    rac4_value_0 = 0;
  }
  else
  {
    rac4_value_0 = *((s32 *) (((s8 *) ((arg0 * 0x54) + 0x31B3F8)) + 8));
  }
  return rac4_value_0;
}
