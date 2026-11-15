/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 64 / disc 60.
 * Function text: 64 B; native catalogue: 60 B; 10 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_0049CCA8 nonmatching/pal/shared/func_L01_0049CCA8.c --diff
 */
#include "common.h"
/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */

extern void *D_00221D70;
void func_L01_0049CCA8(void)
{
  void *temp_v1;
  if (D_00221D70 != NULL)
  {
    if (!((*((s16 *) (((s8 *) D_00221D70) + 0xBC))) == 0x26C2))
    {
      D_00221D70 = NULL;
    }
    else
    {
      temp_v1 = *((void **) (((s8 *) D_00221D70) + 0xAC));
      if (temp_v1 != NULL)
      {
        *((s32 *) (((s8 *) temp_v1) + 8)) = (s32) ((*((s32 *) (((s8 *) temp_v1) + 8))) + 1);
      }
    }
  }
}
