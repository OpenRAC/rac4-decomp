/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 44 / disc 40.
 * Function text: 44 B; native catalogue: 40 B; 13 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_003CD2D8 nonmatching/pal/shared/func_L01_003CD2D8.c --diff
 */
#include "common.h"
/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */

extern void *D_00220C20;
f32 func_L01_003CD2D8(void)
{
  f32 rac4_value_0;
  if (D_00220C20 != NULL)
  {
    rac4_value_0 = *((f32 *) (((s8 *) (*((void **) (((s8 *) D_00220C20) + 0xAC)))) + 0x64));
  }
  else
  {
    rac4_value_0 = 1.0f;
  }
  return rac4_value_0;
}
