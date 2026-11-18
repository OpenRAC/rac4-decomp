#include "common.h"

s16 func_0054BD48(u8 *a0, s32 a1)
{
  s32 *new_var;
  if (a1 >= 0x20)
  {
    a1 = 0x1F;
  }
  if ((*(new_var = &a1)) < 0)
  {
    a1 = 0;
  }
  return *((u8 *) ((a0 + (34 * ((*new_var) * 2))) + 2620));
}
