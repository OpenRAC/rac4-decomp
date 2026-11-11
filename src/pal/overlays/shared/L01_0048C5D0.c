/* cflags: -ffast-math */
#include "common.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

extern f32 func_00454328(f32, f32);
extern f32 func_00454158(f32);
extern f32 func_00454140(f32);

// Advances three angles at obj+0x1A0, +0x1A4 and +0x1A8 by fixed steps and writes values built from
// their sines and cosines, scaled by obj+0x1AC (which rises to 1.0), to x, y and z.
void func_L01_0048C5D0(u8 *moby, u8 *obj, f32 *x, f32 *y, f32 *z) {
    f32 a;
    f32 k;
    f32 s;
    f32 b;
    f32 d;

    if (*(f32 *)(obj + 0x1AC) < 1.0f) {
        *(f32 *)(obj + 0x1AC) = MIN(*(f32 *)(obj + 0x1AC) + 0.020000001f, 1.0f);
    }
    k = 0.02f;
    a = func_00454328(*(f32 *)(obj + 0x1A0), 0.05235988f);
    *(f32 *)(obj + 0x1A0) = a;
    b = func_00454158(a) * 0.3f;
    b = b * *(f32 *)(obj + 0x1AC);
    *x = b;
    s = func_00454158(*(f32 *)(obj + 0x1A4)) * k * func_00454158(*(f32 *)(obj + 0x1A8)) * 1.5f;
    *y = s * *(f32 *)(obj + 0x1AC);
    *z = func_00454158(*(f32 *)(obj + 0x1A4)) * k * func_00454140(*(f32 *)(obj + 0x1A8)) * *(f32 *)(obj + 0x1AC);
    *(f32 *)(obj + 0x1A4) = func_00454328(*(f32 *)(obj + 0x1A4), 0.017453294f);
    *(f32 *)(obj + 0x1A8) = func_00454328(*(f32 *)(obj + 0x1A8), 0.043633234f);
    d = func_00454158(*(f32 *)(obj + 0x1A0) + 2.0f) * 0.03f;
    d = d * *(f32 *)(obj + 0x1AC);
    *z = *z + d;
}
