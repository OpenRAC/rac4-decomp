/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_00409F88(s32 a0, s32 a1, s32 a2);

s32 func_004052B0(s32 p, s32 end, s32 base, s32 a3, s32 a4) {
    for (; p < end; p += 4) {
        if (func_00409F88(p - base, a3, a4) > 0) {
            s32 v = *(s32 *)p;
            s32 t = ((v << 16) & 0xFF0000) | ((v >> 8) & 0xFF) | ((v << 8) & 0xFF000000) | ((v >> 16) & 0xFF00);
            s32 r = ((t << 13) & -0x2000) | ((u32)t >> 19);
            *(s32 *)p = (((r << 8) & -0x100) | ((u32)r >> 24)) ^ 0x09F8ED17;
        }
    }
    return 0;
}
