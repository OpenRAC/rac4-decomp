/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

extern u8 D_003863F8[];

s32 func_L41_0044C940(s32 unused, s32 selector, u32 *size)
{
    if (selector)
        return 0;
    *size = 20;
    return (u32)D_003863F8;
}
