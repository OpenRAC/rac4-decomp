#include "common.h"

extern s32 func_L00_0077D148(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

// Rounds arg0 + 0x28 up to a multiple of 4, adds func_L00_0077D148 of it, rounds again and returns the offset of arg1 words past arg0.
s32 func_L00_00772BC8(s32 arg0, s32 arg1) {
    u32 t;
    u32 b;
    u32 m;
    u32 rem;
    u32 a;

    m = 4;
    t = arg0 + 0x28;
    rem = t % m;
    if (rem != 0) {
        t += m - rem;
    }
    b = t;
    b = b + func_L00_0077D148(b, arg1, 100, 4);
    rem = b % m;
    a = b;
    if (rem != 0) {
        a = b + (m - rem);
    }
    b = a + arg1 * 4;
    return (s32)b - arg0;
}
