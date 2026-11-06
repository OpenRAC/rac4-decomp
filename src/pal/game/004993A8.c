#include "common.h"

extern f32 func_004992B8(f32, f32, f32, f32);
extern s32 func_00454480(s32, s32, f32);

/* Advances a float and uses the filtered value in the callback. */
s32 func_004993A8(f32 *a, s32 b, s32 c, f32 x)
{
    f32 t = *a + x;
    *a = t;
    return func_00454480(b, c, func_004992B8(t, 0.5f, 0.2f, 0.3f));
}
