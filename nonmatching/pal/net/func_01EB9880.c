/* Not matching yet: PAL WIP; main net.text 0x01EB9880, 152B. Not part of the build. */
/*
 * One native-supported local-width/pointer repair emitted124B, not native152B. The compiler merges
 * the initially duplicated status load/range test into the loop, selects BEQZ for known-u16 count,
 * MULT for stride80, and different pointer/status/previousindex allocation and branch scheduling.
 * It is a new object relative to all3 retained140B objects, but does not close the native
 * CFG/instruction-selection residual. No fur
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: f33e398fc02606d2732c6ba6e565f946472e175810d44260e14d0171b287af5f
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EB9880 nonmatching/pal/net/func_01EB9880.c --diff
 */
#include "common.h"

/* Scan records with the native word index and ordered output stores. */
void func_01EB9880(void *arg0, s32 *arg1, s16 *arg2)
{
  s32 temp_v0;
  s32 var_a3;
  u8 *var_a0;
  s32 var_v1;
  u16 temp_a3;
  var_v1 = 0;
  *arg2 = -2;
  *arg1 = 0;
  temp_a3 = *((u16 *) (((s8 *) arg0) + 0x19C));
  var_a3 = temp_a3 - 1;
  if (((s32) temp_a3) > 0)
  {
    var_a0 = (var_a3 * 0x50) + (*((u8 **) (((s8 *) arg0) + 0x184)));
    var_v1 = *(s32 *)var_a0;
    if (((u32)var_v1 - 7U) >= 3U)
    {
      loop_3:
      temp_v0 = var_a3;

      if (var_v1 == 1)
      {
        *arg1 = 7;
        return;
      }
      var_a3 -= 1;
      if ((temp_v0 <= 0) || ((var_a0 -= 0x50, var_v1 = *(s32 *)var_a0, (((u32)var_v1 - 7U) < 3U) != 0)))
      {
        goto block_7;
      }
      goto loop_3;
    }
  }
  block_7:
  if (var_a3 >= 0)
  {
    *arg1 = var_v1;
    *arg2 = var_a3;
  }

}


