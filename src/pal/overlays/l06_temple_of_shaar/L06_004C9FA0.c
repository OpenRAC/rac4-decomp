/* cflags:  -Wuninitialized -Wreturn-type */
#include "pal/decomp.h"
typedef long long s128; typedef unsigned long long u128;
extern int D_00222574;
void func_L06_004C9FA0(void *arg0) {
  s32 *new_var;
  s32 *var_4;
  s32 temp_3;
  s32 var_5;
  new_var = *((s32 **) (((u8 *) arg0) + 0xAC));
  if ((*((u8 *) (((u8 *) arg0) + 0x20))) == 0)
  {
    var_4 = new_var;
    for (var_5 = 0; var_5 < 4; var_5++)
    {
      temp_3 = *var_4;
      if (temp_3 != (-1))
      {
        *((s32 *) (((u8 *) (D_00222574 + (temp_3 << 5))) + 0x18)) = 1;
      }
      var_4 += 1;
    }

  }
}
