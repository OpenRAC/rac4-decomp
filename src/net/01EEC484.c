/* cflags: -O2 -G8 -mno-split-addresses */
#include "common.h"
void func_01EEC484(void *base, s32 value)
{
    *(s32 *)((u8 *)base + 35512) = value;
}
