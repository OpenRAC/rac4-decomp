/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 152 / disc 168.
 * Function text: 152 B; native catalogue: 168 B; 15 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_0048BAB0 nonmatching/pal/game/func_0048BAB0.c --diff
 */
#include "common.h"
/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */

f32 func_0048BAB0(f32 *arg0)
{
  f32 *var_a0;
  f32 temp_f0;
  f32 var_f0;
  f32 var_f1;
  f32 var_f3;
  s32 var_v0;
  var_a0 = arg0;
  var_f3 = 0.0f;
  var_v0 = 2;
  do
  {
    temp_f0 = *var_a0;
    if (temp_f0 < 0.0f)
    {
      var_f1 = -1.0f;
      if (!(temp_f0 < (-1.0f)))
      {
        goto block_6;
      }
      goto block_5;
    }
    var_f1 = 1.0f;
    if (temp_f0 > 1.0f)
    {
      block_5:
      var_f0 = (var_f1 - temp_f0) / (-temp_f0);

    }
    else
    {
      block_6:
      var_f0 = 0.0f;

    }
    if (var_f3 < var_f0)
    {
      var_f3 = var_f0;
    }
    var_v0 -= 1;
    var_a0 += 1;
  }
  while (var_v0 >= 0);
  return var_f3;
}
