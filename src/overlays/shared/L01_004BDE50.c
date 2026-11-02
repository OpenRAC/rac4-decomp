#include "common.h"
extern s32 D_0021DDB4;
void func_L01_004BDE50(void *p) {
 if (D_0021DDB4 == 2) {
  *(s8 *)((u8 *)p + 0x31) = 0;
  *(u16 *)((u8 *)p + 0x34) |= 1;
 } else {
  *(s8 *)((u8 *)p + 0x31) = 1;
  *(u16 *)((u8 *)p + 0x34) &= 0xfffe;
 }
}
