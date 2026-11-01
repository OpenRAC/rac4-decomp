/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

s32 func_L00_0069D408(s32, s32, void *, s32);       /* extern */

s32 func_L00_00712548(void *arg0, s32 arg1) {
  s32 *temp_4;
  void *new_var;
  new_var = arg0 + 0x64;
  temp_4 = new_var - (-((*((s32 *) (((u8 *) arg0) + 0x74))) * 4));
  if ((*temp_4) != (-1))
  {
    *((s32 *) (((u8 *) arg0) + 0x7C)) = arg1;
    return func_L00_0069D408(*temp_4, arg1, arg0, arg1);
  }
  return 0;
}


