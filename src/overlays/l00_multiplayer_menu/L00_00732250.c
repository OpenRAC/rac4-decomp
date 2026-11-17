#include "common.h"

/* Find the last 16-byte entry whose range [f0, f2] contains the value. */
void *func_L00_00732250(s32 unused, s32 val, s16 *e, u32 n) {
    u32 i;
    void *r = 0;
    for (i = 0; i < n; i++, e += 8) {
        if (val < e[0]) continue;
        if (e[1] < val) continue;
        r = e;
        break;
    }
    return r;
}
