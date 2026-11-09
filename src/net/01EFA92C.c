/* cflags: @ee296 -Os -G0 -fno-strict-aliasing -fno-schedule-insns */
#include "common.h"

/* Store a clamped value through the selected field and copy its low half. */
void func_01EFA92C(u8 *p, s32 x, s32 *out)
{
    s32 *dest = (s32 *)(p+0xcc);
    u8 *base;
    s32 index;
    u16 low;
    if (x < 0) x = 0;
    if (out) dest = out;
    *dest=x;
    base=*(u8 **)(p+0x118);
    index=*(s32 *)(p+0xd0);
    low=*(u16 *)dest;
    *(u16 *)(base+index*12+2)=low;
}
