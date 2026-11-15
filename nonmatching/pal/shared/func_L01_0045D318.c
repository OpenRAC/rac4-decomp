/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 40 / disc 44.
 * Function text: 40 B; native catalogue: 44 B; 12 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_0045D318 nonmatching/pal/shared/func_L01_0045D318.c --diff
 */
#include "common.h"
/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */

s32 func_L01_0045D318(void *arg0)
{
  s32 var_a1;
  void *temp_a0;
  int ps2decomp_comparison_0;
  temp_a0 = *((void **) (((s8 *) arg0) + 0xAC));
  var_a1 = 0;
  if ((*((u8 *) (((s8 *) temp_a0) + 0x618))) == 1)
  {
    ps2decomp_comparison_0 = (~(*((s32 *) (((s8 *) temp_a0) + 0x600)))) != 0;
    var_a1 = ps2decomp_comparison_0;
  }
  return var_a1;
}
