/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern u8 D_0019B870[];
extern s32 func_01EF04A4(s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_01EE9D40(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
    return func_01EF04A4(arg1, arg0, 4, 0x32, (s32)D_0019B870, arg5, arg6, arg7);
}
