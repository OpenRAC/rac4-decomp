/* Not matching yet: PAL WIP; main .text 0x0040F138, 408B. Not part of the build. */
/*
 * Native408B versusactual412B. Same0x30 frame, differing s2/s3 allocation, status/default
 * MOVZ/MOVN and returnjoin, loop precomputations/scheduling, two DSLL32/DSRA32 shift-count
 * extension pairs (+A4/+A8,+10C/+110) absent in native. Everyplacement fullunmasked
 * differs305bytes/96words. These are observed residuals for this single coherent source, not a
 * global compiler-impossibility claim or permission for a variant seri
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: b1ced8fa9bd56ba42ddfd58e4d33449bf4522a5e0204dfc964f8e13182a25a34
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_0040F138 nonmatching/pal/game/func_0040F138.c --diff
 */
#include "common.h"
/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */
/* extern */

typedef struct { s32 f0, f4; void *f8; } Arr;
s32 func_004105C0(s32, Arr *);
s32 func_0040F138(u8 *arg0, u32 arg1, void *arg2)
{
  s32 temp_a4_2;
  s32 var_a2;
  s32 var_a2_2;
  s32 var_a4;
  s32 var_v0;
  u64 *temp_a2;
  u64 *var_a3;
  s64 temp_a1;
  s64 temp_a1_2;
  u32 temp_a1_3;
  u32 temp_a4;
  u32 temp_s0;
  u32 temp_s2;
  u32 var_v0_2;
  u8 *var_a5;
  u8 temp_v1;
  u8 temp_v1_2;
  var_v0 = 0x102;
  if ((arg1 != 0) && (((temp_a4 = ((u32) (arg1 + 7)) >> 3, temp_s0 = (temp_a4 != 0) ? (temp_a4) : (1U), temp_s2 = arg1 >> 3, ((*((s32 *) (((s8 *) arg2) + 0))) < ((s32) temp_s0)) == 0)) || ((var_v0 = func_004105C0(temp_s0 + 1, arg2), var_v0 == 0))))
  {
    *((u32 *) (((s8 *) arg2) + 4)) = temp_s0;
    var_a5 = arg0 + arg1;
    var_a3 = *((void **) (((s8 *) arg2) + 8));
    var_a4 = 0;
    if (temp_s2 != 0)
    {
      do
      {
        var_a2 = 1;
        *var_a3 = (u64) (*(var_a5 - 1));
        loop_6:
        temp_a1 = var_a2 * 8;

        temp_v1 = *(var_a5 - var_a2 - 1);
        var_a2 += 1;
        *var_a3 |= ((u64) temp_v1) << temp_a1;
        if (var_a2 < 8)
        {
          goto loop_6;
        }
        var_a4 += 1;
        var_a5 -= 8;
        var_a3 += 1;
      }
      while (var_a4 < ((s32) temp_s2));
    }
    if ((temp_s2 * 8) < ((s32) arg1))
    {
      temp_a4_2 = arg1 % 8;
      var_a2_2 = 1;
      *var_a3 = (u64) (*(var_a5 - 1));
      if (temp_a4_2 > 1)
      {
        do
        {
          temp_a1_2 = var_a2_2 * 8;
          temp_v1_2 = *(var_a5 - var_a2_2 - 1);
          var_a2_2 += 1;
          *var_a3 |= ((u64) temp_v1_2) << temp_a1_2;
        }
        while (var_a2_2 < temp_a4_2);
      }
    }
    temp_a1_3 = *((u32 *) (((s8 *) arg2) + 4));
    temp_a2 = *((void **) (((s8 *) arg2) + 8));
    var_v0 = 0;
    if ((*((u64 *) (((s8 *) (temp_a2 + temp_a1_3)) + (-8)))) == 0)
    {
      if (((s32) temp_a1_3) >= 2)
      {
        var_v0_2 = temp_a1_3 - 1;
        loop_15:
        *((u32 *) (((s8 *) arg2) + 4)) = var_v0_2;

        if ((*((u64 *) (((s8 *) (temp_a2 + var_v0_2)) + (-8)))) == 0)
        {
          if (((s32) var_v0_2) >= 2)
          {
            var_v0_2 -= 1;
            goto loop_15;
          }
        }
      }
      var_v0 = 0;
    }
  }
  return var_v0;
}


