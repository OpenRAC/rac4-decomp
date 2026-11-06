/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern u8 D_0019E470[];
extern s32 func_01EEE13C(s32);
extern s32 func_01EF04A4(s32, s32, s32, s32, s32);

s32 func_01F0845C(s32 arg0)
{
    return func_01EF04A4(func_01EEE13C(arg0), arg0, 0, 0x31, (s32)D_0019E470);
}
