/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "pal/decomp.h"
typedef long long s128; typedef unsigned long long u128;
M2C_UNK func_00474368(void *, M2C_UNK, M2C_UNK);    /* extern */

s32 func_L08_004B9C68(void *arg0, s32 arg1) {
  void *temp_a0;
  int new_var;
  new_var = 4;
  temp_a0 = (*((s32 *) 0x222714)) + ((*((s32 *) (((u8 *) ((*((s32 *) (((u8 *) arg0) + 0xAC))) + (arg1 * new_var))) + 0x10))) << 8);
  if ((*((u8 *) (((u8 *) temp_a0) + 0x20))) == 3)
  {
    return 0;
  }
  func_00474368(temp_a0, 3, -1);
  return 1;
}
