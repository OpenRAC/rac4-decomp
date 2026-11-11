/* cflags:  */
#include "common.h"

extern f32 func_00484F68(u8 *);

// Returns 1 if the value, in 1/4096 units, lies between func_00484F68's result and that result minus
// 0.6 times the moby's +0x48 (either order, by the sign of +0x48), else 0.
s32 func_00484F88(u8 *moby, f32 value) {
    f32 cur = func_00484F68(moby);
    f32 len = *(f32 *)(moby + 0x48);
    s32 v = (s32)(value * 4096.0f + 0.5f);
    s32 lo = (s32)(cur * 4096.0f + 0.5f);
    s32 hi = (s32)((cur - len * 1.2f * 0.5f) * 4096.0f + 0.5f);

    if (len < 0.0f) {
        if (v >= lo && v < hi) {
            return 1;
        }
        return 0;
    }
    if (v <= lo && v > hi) {
        return 1;
    }
    return 0;
}
