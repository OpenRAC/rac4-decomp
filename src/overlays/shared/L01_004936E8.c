/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

/* The second argument carries a record address as a 32-bit word. */
s32 func_00451938(s32 *arg0, s32 arg1, s32 arg2, void *arg3, f32 arg4);
extern s32 D_00222B28;
extern u8 D_003AA350[];

void func_L01_004936E8(void *arg0)
{
    s32 current;
    s32 next;
    s32 remaining;

    remaining = 1;
    next = *((s32 *) ((u8 *) arg0 + 0xAC)) + 0x20;
    do
    {
        current = next;
        next += 0x80;
        func_00451938(&D_00222B28, current, 2, D_003AA350, 1.0f);
        remaining -= 1;
    }
    while (remaining >= 0);
}
