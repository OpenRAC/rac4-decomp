/* cflags:  */
#include "common.h"

s32 func_L00_00703BE8(u8 *a0, s32 a1)
{
  s32 *parameter_view;
  if (a1 >= 0x20)
  {
    a1 = 0x1F;
  }
  parameter_view = &a1;
  if ((*parameter_view) < 0)
  {
    a1 = 0;
  }
  return *((s32 *) ((a0 + (a1 * 0x44)) + 2616));
}
