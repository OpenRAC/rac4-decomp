#include "common.h"

extern f32 func_L00_005FA0C0();

s32 func_L00_005FA0E0(f32 *arg0, f32 arg1) {
    f32 r = func_L00_005FA0C0();
    f32 x = arg0[0x48 / 4];
    s32 a;
    s32 b;
    s32 c;
    s32 res;

    b = (s32)(arg1 * 4096.0f + 0.5f);
    a = (s32)(r * 4096.0f + 0.5f);
    c = (s32)((r - x * 0.5f) * 4096.0f + 0.5f);

    if (x < 0.0f) {
        if (b >= a && b < c) {
            return 1;
        }
        return 0;
    }
    if (a >= b && c < b) {
        return 1;
    }
    return 0;
}
