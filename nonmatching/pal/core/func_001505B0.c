/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 132 / disc 140.
 * Function text: 132 B; native catalogue: 140 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_001505B0 nonmatching/pal/core/func_001505B0.c --diff
 */
#include "common.h"
/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */

void func_001505B0(s32 arg0, f32 *arg1)
{
  f32 *var_a1;
  f32 *var_v1;
  f32 temp_f0;
  f32 var_f1;
  f32 var_f2;
  s32 temp_v0;
  s32 var_a0;
  s32 var_v0;
  var_a1 = arg1;
  var_f2 = 1.0f;
  var_f1 = 0.0f;
  var_v0 = arg0;
  if (arg0 > 0)
  {
    var_v1 = var_a1;
    do
    {
      temp_f0 = *var_v1;
      var_v0 -= 1;
      var_v1 += 1;
      var_f1 += temp_f0;
    }
    while (var_v0 != 0);
  }
  if (var_f1 > 32767.0f)
  {
    var_f2 = 32767.0f / var_f1;
  }
  var_a0 = arg0 - 1;
  if (arg0 > 0)
  {
    do
    {
      temp_v0 = var_a0;
      var_a0 -= 1;
      *var_a1 *= var_f2;
      var_a1 += 1;
    }
    while (temp_v0 > 0);
  }
}
