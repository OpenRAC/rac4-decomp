/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

extern u8 D_00386088[];

s32 func_L41_00447490(s32 unused, s32 selector, u32 *size)
{
    if (selector)
        return 0;
    *size = 24;
    return (u32)D_00386088;
}
