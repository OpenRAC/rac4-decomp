#include "common.h"

extern f32 func_00453B10(f32, f32);
extern void func_00475740(f32 *, f32, f32, f32, f32);
extern f32 func_00475C68(f32, f32, s32);

/* steps *p0 toward a target via func_00475740, snapping when close */
f32 func_00475D98(f32 *p0, f32 *p1, s32 mode, f32 a, f32 b, f32 c, f32 d)
{
    f32 t;

    if (mode == 2) {
        if ((a > 0.0f && *p0 < 0.0f) || (a < 0.0f && *p0 > 0.0f)) {
            mode = 1;
            if (a < 0.0f) {
                mode = -1;
            }
        } else {
            mode = 0;
        }
    }
    func_00475740(p1, func_00475C68(a, *p0, mode), b, c, d);
    *p0 = func_00453B10(*p0, *p1);
    t = func_00475C68(a, *p0, mode);
    if (fabsf(t) < d * 0.01f) {
        *p0 = a;
        *p1 = 0.0f;
        return *p1;
    }
    return t;
}
