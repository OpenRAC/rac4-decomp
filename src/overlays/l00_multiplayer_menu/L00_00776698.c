#include "common.h"

void func_L00_00776698(void *arg0)
{
  s32 var_a1;
  s8 *temp_v0;
  void *var_v1;
  u32 rac4_address_0;
  *((s32 *) (((s8 *) arg0) + 0x1E4)) = 1;
  var_v1 = arg0 + 0x24C;
  *((s8 *) (((s8 *) arg0) + 0)) = 0;
  var_a1 = 0;
  *((s8 *) (((s8 *) arg0) + 0x14C)) = 0;
  *((s8 *) (((s8 *) arg0) + 0x1C0)) = 0;
  do
  {
    rac4_address_0 = ((u32) arg0) + ((u32) 0x238);
    temp_v0 = (s8 *) (rac4_address_0 + ((u32) var_a1));
    *((s32 *) (((s8 *) var_v1) + (-0x64))) = -1;
    *((s32 *) (((s8 *) var_v1) + 0)) = 0;
    var_a1 += 1;
    *temp_v0 = 0;
    var_v1 += 4;
  }
  while (var_a1 < 0x14);
}
