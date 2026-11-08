#include "common.h"

extern s32 D_0023FF00[];

// For each 8-byte entry of arg0 (until the first word goes negative), add the
// value it indexes in arg1 to that slot when the value is at least D_0023FF00[8].
void func_L00_005D3380(s32 *arg0, u8 *arg1) {
    while (arg0[0] >= 0) {
        s32 *p = (s32 *)((arg0[0] << 3) + (u32)arg1);
        s32 off = arg0[1];
        s32 v = p[0];

        if (v >= D_0023FF00[8]) {
            *(s32 *)(v + off) += v;
        }
        arg0 += 2;
    }
}
