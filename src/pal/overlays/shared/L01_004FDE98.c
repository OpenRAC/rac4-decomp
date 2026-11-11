/* cflags: -ffast-math */
#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern f32 func_00475FB0(f32 first, f32 last, f32 fraction);
extern void func_004767E0(s32 a, s32 b, s32 c, f32 d, f32 e, f32 f, f32 g);

// Copies the vector at arg 2, clamps v[1] to +/-0.5235988 and calls func_004767E0 twice.
void func_L01_004FDE98(s32 arg0, s32 arg1, u128 *v, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, f32 x) {
    u128 copy[1];
    f32 *p;
    f32 a;
    f32 b;
    f32 k0;
    f32 k1;
    f32 k2;
    f32 k3;
    f32 k4;
    f32 k5;
    f32 d;
    f32 hi;
    f32 lo;

    copy[0] = *v;
    p = (f32 *)copy;
    if (x < 1.0f) {
        b = x;
        a = func_00475FB0(b, 1.0f, 0.5f);
    } else if (1.0f < x) {
        b = func_00475FB0(x, 1.0f, 0.5f);
        a = x;
    } else {
        a = x;
        b = a;
    }
    if (t3 != 0) {
        k0 = b * 0.0069813174f;
        k3 = b * 0.0020943952f;
        k4 = b * 0.0013962635f;
        lo = -0.5235988f;
        k5 = a * 0.13962635f;
        hi = 0.5235988f;
        k1 = b * 0.02792527f;
        k2 = a * 0.02792527f;
    } else {
        k0 = b * 0.0034906587f;
        k1 = b * 0.013962635f;
        k2 = a * 0.020943953f;
        k4 = b * 0.002792527f;
        lo = -0.5235988f;
        k5 = a * 0.17453294f;
        hi = 0.5235988f;
        k3 = k0;
    }
    d = p[1];
    d = hi < d ? hi : d;
    d = lo > d ? lo : d;
    p[1] = d;
    func_004767E0(t1, t2, 0, d, k0, k1, k2);
    func_004767E0(a3, t0, 0, p[2], k3, k4, k5);
}
