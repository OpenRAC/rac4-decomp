/* cflags: @ee296 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

typedef struct { s32 cap; s32 n; u64 *d; } S;
extern s32 func_00412878(s32, S *);
extern s32 func_004104C8(s32, S *);
s32 func_00412A38(s32 bits, S *s) {
    s32 r = 0;
    s32 k, n, sh, i, t;
    u64 *d;
    u64 top, v;
    if (bits <= 0) {
        return 0;
    }
    if (bits >= 64) {
        k = bits / 64;
        r = func_00412878(k, s);
        if (r != 0) {
            return r;
        }
        bits -= k * 64;
        if (bits == 0) {
            return r;
        }
    }
    n = s->n;
    sh = 64 - bits;
    d = s->d;
    top = d[n - 1] >> sh;
    if (top != 0) {
        if (s->cap < n + 1) {
            r = func_004104C8(n + 2, s);
            if (r != 0) {
                return r;
            }
            d = s->d;
        }
        d[n] = top;
        s->n = s->n + 1;
        d = s->d;
    }
    n--;
    if (n == 0) {
        d[0] <<= bits;
        return 0;
    }
    t = n;
    d[n--] <<= bits;
    if (t > 0) {
        do {
            v = d[n];
            d[n] = v << bits;
            d[n + 1] |= v >> sh;
        } while (n-- > 0);
    }
    return 0;
}
