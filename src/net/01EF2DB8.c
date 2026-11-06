/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern u8 D_0019C6A0[];
extern s32 func_01EEE13C(s32);
extern s32 func_01EF04A4(s32, s32, s32, s32, s32);

s32 func_01EF2DB8(s32 arg0)
{
    return func_01EF04A4(func_01EEE13C(arg0), arg0, 0, 0x51, (s32)D_0019C6A0);
}
