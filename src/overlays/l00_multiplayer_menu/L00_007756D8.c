#include "common.h"

extern s32 func_L00_007755B0(s32 a0, s32 a1);

static inline u32 align_up(u32 v, u32 a) {
    u32 r = v % a;
    if (r != 0) {
        v += a - r;
    }
    return v;
}

// Sums the aligned sizes of a header and two sub-blocks.
s32 func_L00_007756D8(u32 arg0, s32 arg1, s32 arg2) {
    u32 a;

    a = align_up(arg0 + 0x34, 4);
    a = align_up(a + func_L00_007755B0(a, arg1), 4);
    a = align_up(a + func_L00_007755B0(a, arg2), 4);
    return a - arg0;
}
