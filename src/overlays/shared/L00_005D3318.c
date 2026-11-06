#include "common.h"

extern s32 D_0023FF00[];

// For each 8-byte entry of arg0 (until the first word goes negative), look up the
// value it indexes in arg1; when that value is at least D_0023FF00[8] and its own
// slot holds a non-negative index, replace it with the halfword that index marks
// in the table at *arg2.
void func_L00_005D3318(s32 *arg0, u8 *arg1, s32 *arg2) {
    while (arg0[0] >= 0) {
        s32 *p = (s32 *)((arg0[0] << 3) + (u32)arg1);
        s32 off = arg0[1];
        s32 v = p[0];

        if (v >= D_0023FF00[8]) {
            s32 *dst = (s32 *)(v + off);
            s32 x = dst[0];

            if (x >= 0) {
                dst[0] = *(s16 *)((x << 1) + *(s32 *)arg2);
            }
        }
        arg0 += 2;
    }
}
