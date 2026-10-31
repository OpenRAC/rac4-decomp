/* cflags:  -Wuninitialized */
#include "pal/decomp.h"
typedef long long s128; typedef unsigned long long u128;

s32 func_L00_006A1EC0(s32, f32, f32);               /* extern */
s32 func_L00_006A1F88(s32);                         /* extern */

s32 func_L00_007171B0(void *arg0, s32 arg1, f32 fparg0, f32 fparg1) {
  s32 temp_4;
  long snapshot_arg1 = arg1;
  temp_4 = *((s32 *) (((u8 *) arg0) + 0x14));
  if (temp_4 != 0xFFFFFFFF)
  {
    if (func_L00_006A1F88(temp_4) != 0)
    {
      if (snapshot_arg1 != 0)
      {
        return func_L00_006A1EC0(*((s32 *) (((u8 *) arg0) + 0x14)), fparg0, fparg1);
      }
      return 1;
    }
    return 0;
  }
  return 0;
}
