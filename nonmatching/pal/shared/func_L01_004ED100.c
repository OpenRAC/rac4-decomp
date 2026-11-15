/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 120 / disc 124.
 * Function text: 120 B; native catalogue: 124 B; 12 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_004ED100 nonmatching/pal/shared/func_L01_004ED100.c --diff
 */
#include "common.h"
/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */

s32 func_L01_004ED100(void *arg0, s32 arg1)
{
  s32 var_a1;
  void **var_a0;
  void *temp_a0;
  void *temp_v1;
  void *temp_v1_2;
  void *temp_v1_3;
  temp_v1 = *((void **) (((s8 *) arg0) + 0xAC));
  temp_a0 = *((void **) (((s8 *) temp_v1) + 0x2F4));
  *((s32 *) (((s8 *) temp_v1) + 0x320)) = arg1;
  if (temp_a0 != NULL)
  {
    var_a1 = 3;
    *((u8 *) (((s8 *) temp_a0) + 0x30)) = (u8) (*((u8 *) (((s8 *) arg0) + 0x30)));
    *((u16 *) (((s8 *) (*((void **) (((s8 *) temp_v1) + 0x2F4)))) + 0x32)) = (u16) (*((u16 *) (((s8 *) arg0) + 0x32)));
    var_a0 = (*((s32 *) (((s8 *) (*((void **) (((s8 *) temp_v1) + 0x2F4)))) + 0xAC))) + 0xD0;
    do
    {
      temp_v1_2 = *var_a0;
      var_a1 -= 1;
      if (temp_v1_2 != NULL)
      {
        *((u16 *) (((s8 *) temp_v1_2) + 0x32)) = (u16) (*((u16 *) (((s8 *) arg0) + 0x32)));
      }
      var_a0 += 1;
    }
    while (var_a1 >= 0);
    return 1;
  }
  temp_v1_3 = *((void **) (((s8 *) temp_v1) + 0x358));
  if (temp_v1_3 != NULL)
  {
    *((u16 *) (((s8 *) temp_v1_3) + 0x32)) = (u16) (*((u16 *) (((s8 *) arg0) + 0x32)));
  }
  return 1;
}
