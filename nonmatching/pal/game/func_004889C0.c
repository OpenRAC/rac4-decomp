/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 148 / disc 152.
 * Function text: 148 B; native catalogue: 152 B; 15 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_004889C0 nonmatching/pal/game/func_004889C0.c --diff
 */
#include "common.h"
/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */
/* Duplicate return node #3. Try simplifying control flow for better match */
/* Duplicate return node #8. Try simplifying control flow for better match */
/* Duplicate return node #8. Try simplifying control flow for better match */

s32 func_004889C0(f32 fparg0, f32 fparg1, f32 fparg2)
{
  s32 var_v0;
  if (fparg0 <= 0.0f)
  {
    var_v0 = 0;
    if (!((fparg2 <= 0.0f) && (fparg1 > 0.0f)))
    {
    }
    else
    {
      return 1;
    }
    return var_v0;
  }
  var_v0 = 0;
  if (fparg2 > 0.0f)
  {
    if (!(fparg1 <= 0.0f))
    {
      var_v0 = 1;
      if (!(((fparg0 - fparg2) / (fparg1 - fparg2)) < 0.5f))
      {
        var_v0 = 0;
      }
      return var_v0;
    }
    return 1;
  }
  return var_v0;
}
