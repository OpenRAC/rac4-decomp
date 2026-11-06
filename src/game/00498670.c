#include "common.h"

extern f32 func_00498580(f32, f32, f32, f32);
extern s32 func_00453C68(s32, s32, f32);

/* Advances a float and uses the filtered value in the callback. */
s32 func_00498670(f32 *a, s32 b, s32 c, f32 x)
{
    f32 t = *a + x;
    *a = t;
    return func_00453C68(b, c, func_00498580(t, 0.5f, 0.2f, 0.3f));
}
