/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 16/56 (6 words differ).
 * Function text: 56 B; native catalogue: 56 B; 1 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Retains unresolved literal-address accesses from the draft; these are not approved data bindings.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_00159580 nonmatching/pal/core/func_00159580.c --diff
 */
#include "common.h"
/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */

s32 func_00137FB0(void);
extern s32 D_0021DD3C;
s32 func_00159580(void)
{
  s32 rac4_value_0;
  if (D_0021DD3C != 0)
  {
    rac4_value_0 = *((s32 *) (((s8 *) ((void *) 0x1C2000)) + 0x10));
  }
  else
  {
    rac4_value_0 = func_00137FB0();
  }
  return rac4_value_0;
}
