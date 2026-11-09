/* cflags: -ffast-math */
#include "common.h"

extern s32 func_00504840(u32 a0, f32 a1, f32 a2, f32 a3, f32 a4);
extern s32 func_00505118(u32 id, f32 *a, f32 *b, f32 *c, f32 *d);

void func_00497AE0(u32 arg0, u32 arg1, u32 arg2, f32 t, f32 m) {
    f32 x0, y0, x1, y1;
    f32 k;

    func_00505118(arg0, &x0, &y0, &x1, &y1);
    t = t > 1.0f ? 1.0f : t;
    t = t < 0.0f ? 0.0f : t;
    k = m * 1.33333003520965576171875f;
    x0 += m;
    x1 -= m;
    y0 += k;
    y1 -= k;
    switch (arg2) {
    case 0:
        x1 = x0 + (x1 - x0) * t;
        break;
    case 1:
        x0 = x1 - (x1 - x0) * t;
        break;
    case 2:
        y0 = y1 - (y1 - y0) * t;
        break;
    case 3:
        y1 = y0 + (y1 - y0) * t;
        break;
    case 4:
        t = (x1 - x0) * (1.0f - t) * 0.5f;
        x0 += t;
        x1 -= t;
        break;
    case 5:
        t = (y1 - y0) * (1.0f - t) * 0.5f;
        y0 += t;
        y1 -= t;
        break;
    }
    func_00504840(arg1, x0, y0, x1, y1);
}
