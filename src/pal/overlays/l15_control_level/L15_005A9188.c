/* cflags: -ffast-math */
#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern u128 func_00475FC0(u128, u128, f32);

/* Blend the 16-byte samples around t, wrapping the index when it meets the count. */
u128 func_L15_005A9188(const s32 *obj, s32 mode, f32 t) {
    s32 clamped;
    s32 i;
    s32 k;
    s32 n;
    s32 j;

    clamped = 0;
    i = (s32)t;
    if (mode == 0) {
        s32 lim = obj[0] - 2;
        if (i >= lim) {
            i = lim;
            clamped = 1;
        }
    }
    t = t - (f32)i;
    if (clamped)
        t = t < 1.0f ? t : 1.0f;
    k = i;
    n = obj[0];
    j = k + 1;
    if (!(k + 2 < n)) {
        k = k % n;
        j = j % n;
    }
    return func_00475FC0(((const u128 *)(obj + 4))[k], ((const u128 *)(obj + 4))[j], t);
}
