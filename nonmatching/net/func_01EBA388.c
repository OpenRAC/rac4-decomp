/* Not matching yet: BYTES 70/152: structure decoded from retail (packed 6-byte packet, u16 index at +2 and key at +4, 0x50-stride record at *(u8**)(arg0+0x184), handles at +4/+8); residual is arg0 parked in $a3 with a copy back for the call (tools/try_func.py func_01EBA388 --diff) (tools/try_func.py func_01EBA388 --diff). Not part of the build. */
/* Not matching yet: BYTES 78/152: packed packet copy + 0x50-stride record lookup match; residual is register roles (tools/try_func.py func_01EBA388 --diff) (tools/try_func.py func_01EBA388 --diff). Not part of the build. */
/* Not matching yet: BYTES 85/152 (tools/try_func.py func_01EBA388 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    u8 f0;
    u8 f1;
    u16 b;
    u16 c;
} __attribute__((packed)) Type1;

extern s32 func_01EBB0E0(s32, s32, s32, s32);

s32 func_01EBA388(u8 *arg0, s32 arg1, Type1 *arg2)
{
  Type1 packet = *arg2;
  u32 i = packet.b;
  u8 *table = *((u8 **) (arg0 + 0x184));
  u8 *e = ((u8 *) (((i << 2) + i) << 4)) + ((u32) table);
  i = *((u16 *) (e + 0x34));
  if (i == packet.c)
  {
    if (*((s32 *) (e + 4)))
    {
      func_01EBB0E0(arg0, *((s32 *) (e + 4)), 1, 0xD2F3);
    }
    else
    {
      if (*((s32 *) (e + 8)))
      {
        func_01EBB0E0(arg0, *((s32 *) (e + 8)), 1, 0xD2F3);
      }
      return 0;
    }
  }
}
