/* cflags:  -Wuninitialized */
#include "pal/decomp.h"
typedef long long s128; typedef unsigned long long u128;

s32 func_00472E70(M2C_UNK, M2C_UNK);                /* extern */
f32 func_00472F70();                                /* extern */
M2C_UNK func_L05_004DE588(void *, f32, s32, s32, f32, f32, s32, M2C_UNK, void *); /* extern */
s32 D_002222B8 = 47;
s32 D_002222BC = 41;
s32 D_002222C0 = -2146422656;
s32 D_002222C4 = -1;




void func_L05_004DE4B0(void *arg0) {
  f32 temp_f20;
  s32 temp_16;
  s32 temp_16_2;
  void *temp_18;
  temp_18 = ((u8 *) arg0) + 0x10;
  temp_16 = func_00472E70(0x5F, 0x6F);
  func_L05_004DE588(temp_18, *((f32 *) (((u8 *) arg0) + 0x70)), D_002222C0, temp_16, func_00472F70(), 1.0f, D_002222B8, 2, arg0);
  temp_f20 = (*((f32 *) (((u8 *) arg0) + 0x70))) * 0.5f;
  temp_16_2 = func_00472E70(0x6F, 0x7F);
  func_L05_004DE588(temp_18, temp_f20, D_002222C4, temp_16_2, func_00472F70(), 1.0f, D_002222BC, 2, arg0);
}
