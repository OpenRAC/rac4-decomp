/* Not matching yet: BYTES 27/104 (permuter --legal 900 s; best body). Not part of the build. */
/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern u8 D_003E5290[];

extern u8 D_00220A30;
extern s32 D_00220A34;
extern s32 D_00220A0C;
extern s32 D_00220A10;
extern s32 D_00220A14;
extern s32 D_00220A18;
extern s32 D_00220A1C;

void func_L00_007092B0(void)
{
  s32 i;
  u8 *base = D_003E5290;
  u8 *src = (u8 *) (((u32) base) + 0xD000);
  u8 *dst;
  D_00220A30 = 0;
  D_00220A34 = 0;
  dst = (u8 *) (((u32) base) + 0xCFFC);
  for (i = 0x7F; i >= 0; i--)
  {
    *((s32 *) dst) = (s32) src;
    dst -= 0x1A0;
    src -= 0x1A0;
  }

  i = ((u32) base) + 0x8000;
  D_00220A0C = (s32) base;
  ((s32 *) i)[0x13FF] = 0;
  D_00220A10 = 0;
  D_00220A14 = 0;
  D_00220A18 = 0;
  D_00220A1C = 0;
}
