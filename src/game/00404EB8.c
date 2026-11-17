/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_00409F88(s32, s32, s32);

/* Rotates each word in [p, end) by 13 bits when func_00409F88 accepts its address. */
s32 func_00404EB8(s32 p, s32 end, s32 base, s32 a3, s32 a4) {
    for (; p < end; p += 4) {
        if (func_00409F88(p - base, a3, a4) > 0) {
            s32 v = *(s32 *)p;
            *(s32 *)p = ((v << 13) & -0x2000) | ((u32)v >> 19);
        }
    }
    return 0;
}
