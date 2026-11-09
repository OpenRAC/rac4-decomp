/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern unsigned long func_0012FE48(unsigned long a, unsigned long b);

#define sqr64(lo, ho, in) \
    { \
        unsigned long l, h, m, t, x; \
        h = (in); \
        l = h & 0xffffffffUL; \
        h = (h >> 32) & 0xffffffffUL; \
        m = func_0012FE48(l, h); \
        x = func_0012FE48(l, l); \
        h = func_0012FE48(h, h); \
        t = (m & 0xffffffffUL) << 33; \
        l = x + t; \
        h += (m & 0xffffffff80000000UL) >> 31; \
        if (l < t) h++; \
        (lo) = l; \
        (ho) = h; \
    }

/* Squares each word of a into a double-word pair of r. */
void func_L00_00539C00(unsigned long *r, unsigned long *a, int n)
{
    if (n <= 0) return;
    for (;;) {
        sqr64(r[0], r[1], a[0]);
        if (--n == 0) break;
        sqr64(r[2], r[3], a[1]);
        if (--n == 0) break;
        sqr64(r[4], r[5], a[2]);
        if (--n == 0) break;
        sqr64(r[6], r[7], a[3]);
        if (--n == 0) break;
        a += 4;
        r += 8;
    }
}
