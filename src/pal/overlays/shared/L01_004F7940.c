#include "common.h"

void func_L01_004F7940(void *arg0, u8 *arg1)
{
  s32 var_a3;
  void **var_a1;
  void *temp_a2;
  var_a1 = arg1 + 0xD0;
  var_a3 = 3;
  *((s64 *) (((s8 *) arg0) + 0x38)) = (s64) (*((s64 *) (((s8 *) (*((void **) (((s8 *) arg0) + 0xB8)))) + 0x38)));
  do
  {
    temp_a2 = *var_a1;
    var_a3 -= 1;
    var_a1 += 1;
    if (temp_a2 != NULL)
    {
      *((s64 *) (((s8 *) temp_a2) + 0x38)) = (s64) (*((s64 *) (((s8 *) (*((void **) (((s8 *) arg0) + 0xB8)))) + 0x38)));
    }
  }
  while (var_a3 >= 0);
}
