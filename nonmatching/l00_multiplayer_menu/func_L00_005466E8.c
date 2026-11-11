/* Not matching yet: BYTES 13/1672 (tools/try_func.py func_L00_005466E8 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef union {
    unsigned long v;
} Word;

typedef struct {
    Word *d;
    int top;
    int dmax;
    int neg;
    int flags;
} Type1;

typedef struct {
    int tos;
    Type1 bn[1];
} Type3;

extern unsigned long func_0012FE48(unsigned long, unsigned long);
extern void func_00538180(Type1 *);
extern int func_L00_005377B0(Type1 *r, Type1 *a, Type1 *b);
extern int func_L00_005379F8(Type1 *r, Type1 *a, Type1 *b);
extern int func_L00_00537BB0(Type1 *r, Type1 *a, Type1 *b);
extern int func_L00_00537F68(Type1 *);
extern void func_L00_00538128(Type1 *a);
extern Type1 *func_L00_005382C8(Type1 *a, int words);
extern Type1 *func_L00_005383D0(Type1 *a, Type1 *b);
extern int func_L00_00538508(Type1 *a, unsigned long w);
extern int func_L00_00538770(Type1 *a, Type1 *b);
extern int func_L00_00538938(Type1 *r, Type1 *a, int n);
extern unsigned long func_L00_00539898(unsigned long *rp, unsigned long *ap, int num, unsigned long w);
extern unsigned long func_L00_0053BCF0(unsigned long, unsigned long, unsigned long);
extern int func_L00_00547558(Type1 *r, Type1 *a, int n);

#define LO(a) ((a) & 0xffffffffUL)
#define HI(a) (((a) >> 32) & 0xffffffffUL)

int func_L00_005466E8(Type1 *dv, Type1 *rm, Type1 *num, Type1 *divisor, Type3 *ctx) {
    int shift, i, j, loop;
    Type1 *tmp, wnum, *snum, *sdiv, *res;
    Word *resp, *wnump;
    unsigned long d0, d1;
    int num_n, div_n;

    if (divisor->top == 0 || (divisor->top == 1 && divisor->d[0].v == 0)) {
        return 0;
    }
    if (func_L00_00538770(num, divisor) < 0) {
        if (rm != NULL) {
            if (func_L00_005383D0(rm, num) == NULL) return 0;
        }
        if (dv != NULL) func_L00_00538508(dv, 0);
        return 1;
    }

    tmp = &ctx->bn[ctx->tos];
    tmp->neg = 0;
    snum = &ctx->bn[ctx->tos + 1];
    sdiv = &ctx->bn[ctx->tos + 2];
    if (dv == NULL)
        res = &ctx->bn[ctx->tos + 3];
    else
        res = dv;

    shift = 64 - (func_L00_00537F68(divisor) % 64);
    func_L00_00538938(sdiv, divisor, shift);
    sdiv->neg = 0;
    shift += 64;
    func_L00_00538938(snum, num, shift);
    snum->neg = 0;
    num_n = snum->top;
    div_n = sdiv->top;
    loop = num_n - div_n;

    func_00538180(&wnum);
    wnum.dmax = snum->dmax + 1;
    wnum.d = &snum->d[loop];
    wnum.top = div_n;

    d0 = sdiv->d[div_n - 1].v;
    d1 = (div_n == 1) ? 0 : sdiv->d[div_n - 2].v;

    wnump = &snum->d[num_n - 1];

    if (((loop + 1 <= res->dmax) ? res : func_L00_005382C8(res, loop + 1)) == NULL) return 0;
    res->neg = num->neg ^ divisor->neg;
    res->top = loop;
    resp = &res->d[loop - 1];

    if (((div_n + 1 <= tmp->dmax) ? tmp : func_L00_005382C8(tmp, div_n + 1)) == NULL) goto err;

    if (func_L00_00538770(&wnum, sdiv) >= 0) {
        if (!func_L00_005379F8(&wnum, &wnum, sdiv)) goto err;
        resp->v = 1;
        res->d[res->top - 1].v = 1;
    } else {
        res->top--;
    }
    resp--;

    for (i = 0; i < loop - 1; i++) {
        unsigned long q, l0;
        unsigned long n0, n1;
        unsigned long t1l, t1h, t2l, t2h, t3l, t3h, ql, qh, t3t;

        wnum.d--;
        wnum.top++;
        n0 = wnump[0].v;
        n1 = wnump[-1].v;
        if (n0 == d0)
            q = (unsigned long)-1;
        else
            q = func_L00_0053BCF0(n0, n1, d0);
        t1h = n0;
        t1l = n1;
        for (;;) {
            t2l = LO(d1); t2h = HI(d1);
            ql = LO(q); qh = HI(q);
            {
                unsigned long m, m1, lt, ht;
                lt = t2l; ht = t2h;
                m = qh * lt;
                lt = ql * lt;
                m1 = ql * ht;
                ht = qh * ht;
                m = m + m1; if (m < m1) ht += (1UL << 32);
                ht += HI(m);
                m1 = LO(m) << 32;
                lt = lt + m1; if (lt < m1) ht++;
                t2l = lt; t2h = ht;
            }
            t3t = LO(d0); t3h = HI(d0);
            {
                unsigned long m, m1, lt, ht;
                lt = t3t; ht = t3h;
                m = qh * lt;
                lt = ql * lt;
                m1 = ql * ht;
                ht = qh * ht;
                m = m + m1; if (m < m1) ht += (1UL << 32);
                ht += HI(m);
                m1 = LO(m) << 32;
                lt = lt + m1; if (lt < m1) ht++;
                t3t = lt; t3h = ht;
            }
            t3l = t1l - t3t;
            if (t3l > t1l) t3h++;
            t3h = t1h - t3h;

            if (t3h) break;
            if (t2h < t3l) break;
            if (t2h == t3l && t2l <= wnump[-2].v) break;
            q--;
        }
        l0 = func_L00_00539898(&tmp->d->v, &sdiv->d->v, div_n, q);
        tmp->d[div_n].v = l0;
        for (j = div_n + 1; j > 0; j--)
            if (tmp->d[j - 1].v) break;
        tmp->top = j;

        j = wnum.top;
        func_L00_00537BB0(&wnum, &wnum, tmp);
        snum->top = snum->top + wnum.top - j;

        if (wnum.neg) {
            q--;
            j = wnum.top;
            func_L00_005377B0(&wnum, &wnum, sdiv);
            snum->top += wnum.top - j;
        }
        (resp--)->v = q;
        wnump--;
    }
    func_L00_00538128(snum);
    if (rm != NULL) {
        i = num->neg;
        func_L00_00547558(rm, snum, shift);
        rm->neg = i;
    }
    return 1;
err:
    return 0;
}
