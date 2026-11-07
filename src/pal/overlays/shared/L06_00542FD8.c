#include "common.h"

f32 func_L06_00542FD8(f32 *arg0, f32 fparg0)
{
  f32 rac4_value_0;
  f32 temp_f1;
  f32 temp_f1_2;
  f32 var_f0;
  temp_f1_2 = (*arg0) + fparg0;
  *arg0 = temp_f1_2;
  if (temp_f1_2 > 2.0f)
  {
    var_f0 = temp_f1_2 - 2.0f;
    goto block_4;
  }
  if (temp_f1_2 < 0.0f)
  {
    var_f0 = temp_f1_2 + 2.0f;
    block_4:
    *arg0 = var_f0;

  }
  temp_f1 = *arg0;
  if (temp_f1 <= 1.0f)
  {
    rac4_value_0 = temp_f1;
  }
  else
  {
    rac4_value_0 = 2.0f - temp_f1;
  }
  return rac4_value_0;
}
