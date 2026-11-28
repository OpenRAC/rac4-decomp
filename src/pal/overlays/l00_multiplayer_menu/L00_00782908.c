#include "common.h"

extern s32 func_L00_005C1A58(s32 first, s32 second, f32 scale);
extern f32 D_L00_00220494;
extern f32 D_L00_002204B4;

/* Convert and scale the result for a complete input pair. */
f32 func_L00_00782908(s32 arg0, s32 arg1, s32 first, s32 second)
{
    f32 result;
    if (first != 0 && second != 0) {
        result = (f32)func_L00_005C1A58(first, second, D_L00_00220494) / D_L00_002204B4;
    } else {
        result = 0.0f;
    }
    return result * 512.0f;
}
