/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 52/176 (20 words differ); BYTES 53/176 (20 words differ); BYTES 54/176 (20 words differ).
 * Function text: 176 B; native catalogue: 176 B; 15 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_004BD990 nonmatching/pal/game/func_004BD990.c --diff
 */
#include "common.h"
/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */
/* extern */

s32 func_00506BB8();
s32 func_004BD990(void)
{
  s32 temp_v1;
  s32 var_a0;
  s32 var_a2;
  s32 var_v1;
  void *temp_a1;
  void *temp_a3;
  void *temp_v1_2;
  void *var_v0;
  temp_a3 = (func_00506BB8() * 0x534) + 0x30A6F0;
  var_a2 = -1;
  var_a0 = 0;
  if ((*((s32 *) (((s8 *) temp_a3) + 0x518))) > 0)
  {
    do
    {
      temp_a1 = temp_a3 + 0x4C8;
      if (var_a2 == (-1))
      {
        if (var_a0 < 0)
        {
          temp_v1 = *((s32 *) (((s8 *) temp_a1) + 0x54));
          var_v1 = temp_v1 * 0x18;
          if (temp_v1 < 0)
          {
            var_v0 = NULL;
          }
          else
          {
            goto block_7;
          }
        }
        else
        {
          var_v1 = var_a0 * 0x18;
          block_7:
          var_v0 = (*((s32 *) (((s8 *) temp_a1) + 0x34))) + var_v1;

        }
        temp_v1_2 = *((void **) (((s8 *) var_v0) + 8));
        if ((*((s32 *) (((s8 *) temp_v1_2) + 8))) != 1)
        {
          var_a2 = ((*((u8 *) (((s8 *) temp_v1_2) + 2))) != 0) ? (var_a0) : (var_a2);
        }
      }
      var_a0 += 1;
    }
    while (var_a0 < (*((s32 *) (((s8 *) temp_a1) + 0x50))));
  }
  return var_a2;
}
