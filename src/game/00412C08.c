/* cflags: @ee296 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

typedef struct { s32 cap; s32 n; u64 *d; } S;
extern s32 func_00412BB0(s32, S *);
s32 func_00412C08(s32 bits, S *s) {
    s32 r;
    s32 limbs;
    s32 n, cnt, sh;
    u64 *p, *d;
    u64 v;
    if (bits <= 0) {
        return 0;
    }
    if (bits >= 64) {
        limbs = bits / 64;
        r = func_00412BB0(limbs, s);
        if (r != 0) {
            return r;
        }
        bits -= limbs * 64;
        if (bits == 0) {
            return r;
        }
    }
    sh = 64 - bits;
    n = s->n - 1;
    d = s->d;
    if (n > 0) {
        p = d;
        cnt = n;
        do {
            cnt--;
            *p = (p[0] >> bits) | (p[1] << sh);
            p++;
        } while (cnt != 0);
    }
    v = d[n] >> bits;
    d[n] = v;
    if (v == 0) {
        if (n == 0) {
            return 0;
        }
        s->n = s->n - 1;
    }
    return 0;
}
