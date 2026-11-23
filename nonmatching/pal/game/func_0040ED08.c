/* Not matching yet: PAL WIP; main .text 0x0040ED08, 224B. Not part of the build. */
/*
 * Native224B versusactual200B atmain/front/L00. Nativeearlyv0zero, headerhelds2/counts0/basea1
 * versusoursheaderhelds0/counta0/basev1, different BEQL/BNEjoins and returnrestores,
 * internalbranch/padding schedules remain. No onepaddingclassification or
 * globalcompilerimpossibility asserted.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: b2f99cad67abda2beadf12d8060299464522e326f788be6b2be13a42fe189280
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_0040ED08 nonmatching/pal/game/func_0040ED08.c --diff
 */
#include "common.h"
/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */
/* extern */
/* Duplicate return node #15. Try simplifying control flow for better match */

s32 func_004104C8(s32, void *);
s32 func_0040ED08(u64 arg0, void *arg1)
{
  s32 temp_s0;
  s32 temp_s0_2;
  s32 temp_v0;
  s32 var_s1;
  u64 *var_v1;
  u64 temp_v0_2;
  u64 *temp_a1;
  u64 temp_v1;
  temp_a1 = *((u64 **) (((s8 *) arg1) + 8));
  temp_v1 = (*temp_a1) + arg0;
  *temp_a1 = temp_v1;
  if (temp_v1 < arg0)
  {
    temp_s0 = *((s32 *) (((s8 *) arg1) + 4));
    var_s1 = 1;
    if (temp_s0 > 1)
    {
      var_v1 = temp_a1 + 1;
      loop_3:
      temp_v0_2 = (*var_v1) + 1;

      *var_v1 = temp_v0_2;
      var_v1 += 1;
      if (temp_v0_2 == 0)
      {
        var_s1 = (s32) ((u32) var_s1 + 1u);
        if (var_s1 >= temp_s0)
        {
          goto block_5;
        }
        goto loop_3;
      }
      return 0;
    }
    block_5:
    temp_s0_2 = (s32) ((u32) temp_s0 + 1u);

    if ((*((s32 *) (((s8 *) arg1) + 0))) >= temp_s0_2)
    {
      goto block_14;
    }
    temp_v0 = func_004104C8((s32) ((u32) temp_s0_2 + 1u), arg1);
    if (temp_v0 == 0)
    {
      block_14:
      *(var_s1 + (*((u64 **) (((s8 *) arg1) + 8)))) = 1;

      *((s32 *) (((s8 *) arg1) + 4)) = temp_s0_2;
      return 0;
    }
    return temp_v0;
  }
  return 0;
}


