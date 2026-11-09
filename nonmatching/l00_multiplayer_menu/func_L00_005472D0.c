/* Not matching yet: BYTES 16/556 (tools/try_func.py func_L00_005472D0 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 {
    u64 *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} Type1;

typedef union Word {
    u64 w;
    void *p;
} Word;

typedef struct Type2 {
    s32 tos;
    Type1 bn[1];
} Type2;

typedef struct Type3 {
    s32 f0;
    s32 f4;
    s32 ri;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    Type1 N;
    s32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
    s32 f44;
    u64 n0;
} Type3;

extern u64 func_0012FE48(u64, u64);
extern int func_L00_005379F8(Type1 *r, Type1 *a, Type1 *b);
extern void func_L00_00538128(Type1 *a);
extern Type1 *func_L00_005382C8(Type1 *a, int n);
extern int func_L00_005383D0(Type1 *, Type1 *);
extern int func_L00_00538770(Type1 *, Type1 *);
extern u64 func_L00_00539520(u64 *, u64 *, s32, u64);
extern int func_L00_00547558(Type1 *, Type1 *, s32);

int func_L00_005472D0(Type1 *ret, Type1 *a, Type3 *mont, Type2 *ctx) {
    int retn = 0;
    Type1 *n;
    Type1 *r;
    u64 *rp;
    u64 *np;
    u64 *nrp;
    u64 n0;
    u64 v;
    u64 t;
    u64 c;
    int al;
    int nl;
    int max;
    int i;

    r = &ctx->bn[ctx->tos];
    if (!func_L00_005383D0(r, a))
        goto err;
    n = &mont->N;
    al = mont->ri;
    nl = n->top;
    if (al == 0 || nl == 0) {
        r->top = 0;
        return 1;
    }
    max = nl + al + 1;
    if ((r->dmax >= max ? r : func_L00_005382C8(r, max)) == NULL)
        goto err;
    if ((ret->dmax >= max ? ret : func_L00_005382C8(ret, max)) == NULL)
        goto err;
    r->neg = a->neg ^ n->neg;
    np = n->d;
    rp = r->d;
    nrp = &r->d[nl];
    for (i = r->top; i < max; i++)
        ((Word *)r->d)[i].w = 0;
    r->top = max;
    n0 = mont->n0;
    c = 0;
    for (i = 0; i < nl; i++) {
        v = func_L00_00539520(rp, np, nl, func_0012FE48(*rp, n0));
        rp++;
        v += c;
        c = v < c;
        t = *nrp + v;
        c += t < v;
        *nrp = t;
        nrp++;
    }
    *nrp = c;
    func_L00_00538128(r);
    func_L00_00547558(ret, r, mont->ri << 6);
    if (func_L00_00538770(ret, &mont->N) >= 0)
        func_L00_005379F8(ret, ret, &mont->N);
    retn = 1;
err:
    return retn;
}
