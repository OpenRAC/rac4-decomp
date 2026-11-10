#include "common.h"

f32 *func_00595DA0(s32);
s32 func_L01_00501C18(void *arg0)
{
  s32 temp_a1;
  s32 var_a0;
  s32 var_v0;
  u8 temp_v1;
  var_v0 = 0;
  if (!((*func_00595DA0(*((s32 *) (((s8 *) (*((void **) (((s8 *) arg0) + 0xAC)))) + 0x1D8)))) <= 0.0f))
  {
    var_a0 = 0;
    if ((*((u8 *) (((s8 *) arg0) + 0x69))) == 3)
    {
      temp_v1 = *((u8 *) (((s8 *) arg0) + 0x20));
      if ((temp_v1 ^ 6) != 0)
        temp_a1 = 0;
      else
        temp_a1 = 0x28;
      var_a0 = ((temp_v1 ^ 8) == 0) ? (temp_a1 | 0x84) : (temp_a1);
    }
    return var_a0;
  }
  return var_v0;
}
