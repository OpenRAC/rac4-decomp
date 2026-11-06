#include "common.h"
s32 func_L01_0045C658(const u8 *object)
{
 const u8 *state=*(const u8 **)(object+0xAC);
 if (*(const s32 *)(state+0x410)!=0) {
  s32 value=*(const s32 *)(state+0x42C);
  return value!=0 ? value : 2;
 }
 return 3;
}
