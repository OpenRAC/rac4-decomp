#include "common.h"

f32 func_L01_00519218(void *arg0)
{
  f32 var_f0;
  u8 temp_v1;
  temp_v1 = *((u8 *) (((s8 *) arg0) + 0x20));
  if (temp_v1 != 1)
  {
    var_f0 = 0.0f;
    if (temp_v1 == 4)
    {
      return -1.0f;
    }
    {
      f32 rac4_value_0 = var_f0;
      return rac4_value_0;
    }
  }
  var_f0 = 1.0f;
  return var_f0;
}
