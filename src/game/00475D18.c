/* cflags: -ffast-math */
#include "common.h"
extern f32 func_00475C68(f32, f32, s32);
extern f32 func_00453B10(f32, f32);
f32 func_00475D18(f32 a, f32 b, f32 *p, s32 mode)
{
    f32 t = func_00475C68(a, *p, mode);
    t = t > b ? b : t;
    t = t < -b ? -b : t;
    *p = func_00453B10(*p, t);
    return func_00475C68(a, *p, mode);
}
