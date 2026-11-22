#include "common.h"
f32 func_00548398(s32 a, s32 b, s32 c, s32 d);
s32 func_004332B0(s32 a);
s32 func_005484C8(s32 a0, s32 a1) {
    if (a0 == 8) return func_004332B0(a1);
    return func_00548398(a0, a1, 0, 1) * 10.0f;
}
