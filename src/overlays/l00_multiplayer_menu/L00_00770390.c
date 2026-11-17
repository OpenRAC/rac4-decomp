#include "common.h"

extern s32 func_L00_0077D148(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

static inline u32 align(u32 x, u32 a) {
    u32 hi = x % a;
    if (hi != 0) {
        x += a - hi;
    }
    return x;
}

// Aligns arg0 + 0x50 up to 4, reserves an allocation of arg1 * 2 bytes, aligns again and returns the offset past arg1 * 8 bytes.
s32 func_L00_00770390(s32 arg0, s32 arg1) {
    u32 p;

    p = align(arg0 + 0x50, 4);
    p += func_L00_0077D148(p, arg1 * 2, 0x1A4, 4);
    p = align(p, 4);
    p += arg1 * 8;
    return p - arg0;
}
