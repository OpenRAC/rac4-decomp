#include "common.h"
s32 func_004E2EF0(s32 sound, u32 flags, void *moby);
void func_L01_004EDC50(void *arg0, void *arg1, s32 arg2) {
 s32 *entries;
 s32 *p;
 s32 value;
 s32 bit;
 s32 i;
 s32 active;
 s32 occupied;
 s32 freeIndex;
 if (arg2 != 0 && *(u8 *)((s8 *)arg1 + 0x2F1) != 0) {
  entries = (s32 *)((s8 *)arg1 + 0x378);
  freeIndex = -1; occupied = 0; active = 0; i = 0; p = entries;
  do {
   value = *p;
   if (value == arg2) return;
   if (value == 0) freeIndex = i;
   else occupied++;
   bit = ((s32)*(u8 *)((s8 *)arg1 + 0x2F1) >> i) & 1;
   p++; i++; active += bit;
  } while (i < 6);
  if (freeIndex >= 0 && occupied < active) {
   func_004E2EF0(10, 0, arg0);
   *(s32 *)((u32)entries + ((u32)freeIndex << 2)) = arg2;
  }
 }
}
