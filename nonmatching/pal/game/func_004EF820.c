/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 344 / disc 360.
 * Function text: 344 B; native catalogue: 360 B; 15 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_004EF820 nonmatching/pal/game/func_004EF820.c --diff
 */
#include "common.h"
/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */

void func_004EF820(void *arg0, void *arg1, f32 fparg0)
{
  f32 temp_f0;
  f32 temp_f12;
  f32 temp_f3;
  s32 temp_v0;
  u32 temp_a3;
  u32 var_a0;
  void *temp_a2;
  void *var_a2;
  void *var_v0;
  void *var_v1;
  temp_a2 = *((void **) (((s8 *) arg0) + 8));
  temp_a3 = *((u32 *) (((s8 *) temp_a2) + 0x10));
  if (temp_a3 != 0)
  {
    if (!(temp_a3 != 1))
    {
      *((f32 *) (((s8 *) arg1) + 0)) = (f32) (*((f32 *) (((s8 *) (*((void **) (((s8 *) temp_a2) + 0xC)))) + 0xC)));
      *((f32 *) (((s8 *) arg1) + 4)) = (f32) (*((f32 *) (((s8 *) (*((void **) (((s8 *) (*((void **) (((s8 *) arg0) + 8)))) + 0xC)))) + 0x10)));
      *((f32 *) (((s8 *) arg1) + 8)) = (f32) (*((f32 *) (((s8 *) (*((void **) (((s8 *) (*((void **) (((s8 *) arg0) + 8)))) + 0xC)))) + 0x14)));
      *((f32 *) (((s8 *) arg1) + 0xC)) = (f32) (*((f32 *) (((s8 *) (*((void **) (((s8 *) (*((void **) (((s8 *) arg0) + 8)))) + 0xC)))) + 0x18)));
    }
    else
    {
      var_v1 = *((void **) (((s8 *) temp_a2) + 0xC));
      var_a0 = 0;
      var_a2 = var_v1;
      if (temp_a3 != 0)
      {
        var_v0 = *((void **) (((s8 *) var_v1) + 0));
        if ((var_v0 != NULL) && ((*((f32 *) (((s8 *) var_v1) + 8))) <= fparg0))
        {
          loop_8:
          var_v1 = var_v0;

          var_a0 += 1;
          if (var_a0 < temp_a3)
          {
            var_v0 = *((void **) (((s8 *) var_v1) + 0));
            if ((var_v0 != NULL) && ((*((f32 *) (((s8 *) var_v1) + 8))) <= fparg0))
            {
              var_a2 = var_v1;
              goto loop_8;
            }
          }
        }
      }
      temp_f0 = *((f32 *) (((s8 *) var_a2) + 8));
      temp_v0 = *((s32 *) (((s8 *) temp_a2) + 0x14));
      temp_f12 = (fparg0 - temp_f0) / ((*((f32 *) (((s8 *) var_v1) + 8))) - temp_f0);
      if ((temp_v0 >= 0) && (temp_v0 < 2))
      {
        temp_f3 = 1.0f - temp_f12;
        *((f32 *) (((s8 *) arg1) + 0)) = (f32) ((temp_f3 * (*((f32 *) (((s8 *) var_a2) + 0xC)))) + (temp_f12 * (*((f32 *) (((s8 *) var_v1) + 0xC)))));
        *((f32 *) (((s8 *) arg1) + 4)) = (f32) ((temp_f3 * (*((f32 *) (((s8 *) var_a2) + 0x10)))) + (temp_f12 * (*((f32 *) (((s8 *) var_v1) + 0x10)))));
        *((f32 *) (((s8 *) arg1) + 8)) = (f32) ((temp_f3 * (*((f32 *) (((s8 *) var_a2) + 0x14)))) + (temp_f12 * (*((f32 *) (((s8 *) var_v1) + 0x14)))));
        *((f32 *) (((s8 *) arg1) + 0xC)) = (f32) ((temp_f3 * (*((f32 *) (((s8 *) var_a2) + 0x18)))) + (temp_f12 * (*((f32 *) (((s8 *) var_v1) + 0x18)))));
      }
    }
  }
}
