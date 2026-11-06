/* cflags: -O2 -G8 -Wa,-G0 -Wuninitialized */
#include "common.h"

extern f32 func_00454158(f32);

f32 func_L00_005ABA00(f32 angle)
{
    f32 value = func_00454158(angle * 1.5707964f);
    if (value < 0.1f)
        value = 0.0f;
    return value;
}
