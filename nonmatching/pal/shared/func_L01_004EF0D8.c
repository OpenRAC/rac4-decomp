/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 3/36 (3 words differ).
 * Function text: 36 B; native catalogue: 36 B; 12 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_004EF0D8 nonmatching/pal/shared/func_L01_004EF0D8.c --diff
 */
#include "common.h"
/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */

s32 func_L01_004EF0D8(void *arg0)
{
  s32 var_v0;
  if (!((*((s16 *) (((s8 *) arg0) + 0xBC))) != 0x2038))
  {
    var_v0 = (*((s32 *) (((s8 *) (*((void **) (((s8 *) arg0) + 0xAC)))) + 0x320))) != 0;
  }
  else
  {
    var_v0 = 0;
  }
  return var_v0 ^ 1;
}
