/* cflags: -ffast-math */
#include "common.h"
extern f32 func_00476548(f32, f32, s32);
extern f32 func_00454328(f32, f32);
f32 func_004765F8(f32 a, f32 b, f32 *p, s32 mode)
{
    f32 t = func_00476548(a, *p, mode);
    t = t > b ? b : t;
    t = t < -b ? -b : t;
    *p = func_00454328(*p, t);
    return func_00476548(a, *p, mode);
}
