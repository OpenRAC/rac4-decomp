
#include "common.h"

extern const f32 D_001A19D0[];

/* Returns the first index whose squared distance improves the external threshold. */
s32 func_0014A0B8(f32 *arg0, f32 *arg1, s32 arg2) {
    s32 i = 0;
    f32 best = D_001A19D0[0];
    s32 result = 0;

    if (arg2 > 0) {
        f32 refx = arg0[0];
        f32 refy = arg0[1];
        for (; i < arg2; i++) {
            f32 delta = *arg1++ - refx;
            f32 distance = delta * delta;
            delta = *arg1++ - refy;
            distance = distance + delta * delta;
            if (distance < best) {
                best = distance;
                result = i;
            }
        }
    }
    return result;
}





