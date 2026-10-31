/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

/* Clear two bytes and set the low two bits of the halfword. */
void func_L13_004BFE50(void *arg0)
{
    *(s8 *)((u8 *)arg0 + 0x67) = 0;
    *(s8 *)((u8 *)arg0 + 0x31) = 0;
    *(u16 *)((u8 *)arg0 + 0x34) |= 3;
}
