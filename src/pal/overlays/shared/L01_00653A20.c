/* cflags: -O2 -G8 */
#include "common.h"

void *func_0046DD08(s32, s32, s32);                 /* extern */

s32 func_L01_00653A20(void *arg0) {
  s32 var_2;
  void *temp_2;
  temp_2 = func_0046DD08(*((s16 *) (((u8 *) arg0) + 0xBC)), 20, 8);
  if (temp_2 == ((void *) 0))
  {
    goto block_2;
  }
  var_2 = 0;
  if ((*((s32 (**)(void *)) (((u8 *) temp_2) + 4)))(arg0) == 0)
  {
    {
      return var_2;
    }
  }
  block_2:
  var_2 = 1;

  return var_2;
}
