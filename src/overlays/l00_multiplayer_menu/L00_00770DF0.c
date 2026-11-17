#include "common.h"

extern s32 func_L00_0077D148(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

/* computes a size with three 4-byte-aligned sections */
s32 func_L00_00770DF0(u32 a, s32 n) {
    u32 p;
    u32 q;
    u32 m;
    u32 al;
    p = a + func_L00_0077D148(a, n * 2, 0x48, 4);
    al = 4;
    m = p % al;
    q = p;
    if (m != 0) {
        q = p + (al - m);
    }
    p = q + n * 4;
    m = p % al;
    q = p;
    if (m != 0) {
        q = p + (al - m);
    }
    p = q + n * 8;
    return p - a;
}
