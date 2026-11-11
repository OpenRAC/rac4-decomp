#include "common.h"

s32 func_00548078(u8 *a0, s32 a1)
{
  s32 *new_var;
  if (a1 >= 0x20)
  {
    a1 = 0x1F;
  }
  new_var = &a1;
  if ((*new_var) < 0)
  {
    a1 = 0;
  }
  return *((s32 *) ((a0 + (a1 * 0x44)) + 0xA34));
}
