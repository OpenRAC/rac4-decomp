/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern unsigned long func_0012FE48(unsigned long a, unsigned long b);

#define mul64(l, h, bl, bh) \
    { \
        unsigned long m, m1, lt, ht; \
        lt = l; \
        ht = h; \
        m = func_0012FE48(bh, lt); \
        lt = func_0012FE48(lt, bl); \
        m1 = func_0012FE48(bl, ht); \
        ht = func_0012FE48(ht, bh); \
        m = (m + m1) & 0xffffffffffffffffUL; \
        if (m < m1) ht += (1UL << 32); \
        ht += (m >> 32) & 0xffffffffUL; \
        m1 = (m & 0xffffffffUL) << 32; \
        lt = (lt + m1) & 0xffffffffffffffffUL; \
        if (lt < m1) ht++; \
        (l) = lt; \
        (h) = ht; \
    }

#define mul(r, a, bl, bh, c) \
    { \
        unsigned long l, h; \
        h = (a); \
        l = h & 0xffffffffUL; \
        h = (h >> 32) & 0xffffffffUL; \
        mul64(l, h, (bl), (bh)); \
        l = (l + (c)) & 0xffffffffffffffffUL; \
        if (l < (c)) h++; \
        (c) = h & 0xffffffffffffffffUL; \
        (r) = l; \
    }

/* Multiplies each word of a by w into r, returning the carry word. */
unsigned long func_L00_00539898(unsigned long *rp, unsigned long *ap, int num, unsigned long w)
{
    unsigned long carry = 0;
    unsigned long bl, bh;

    if (num <= 0) return 0;

    bl = w & 0xffffffffUL;
    bh = (w >> 32) & 0xffffffffUL;

    for (;;) {
        mul(rp[0], ap[0], bl, bh, carry);
        if (--num == 0) break;
        mul(rp[1], ap[1], bl, bh, carry);
        if (--num == 0) break;
        mul(rp[2], ap[2], bl, bh, carry);
        if (--num == 0) break;
        mul(rp[3], ap[3], bl, bh, carry);
        if (--num == 0) break;
        ap += 4;
        rp += 4;
    }
    return carry;
}
