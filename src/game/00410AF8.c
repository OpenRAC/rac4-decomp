/* cflags: @ee296 -O2 -G0 -fno-strict-aliasing -fno-optimize-sibling-calls */
#include "common.h"

typedef struct { s32 cap; s32 n; u64 *d; } S;
extern u64 func_0012FE48(u64, u64);
extern s32 func_004105C0(s32, S *);
extern void func_00403308(void *, s32, s32);
extern void func_00412DD8(u64, S *, s32, s32, S *, s32);
extern s32 func_00412D00(s32, S *);
extern s32 func_00412A38(s32, S *);
extern void func_00412FB8(S *, S *);
extern s32 func_00412BB0(s32, S *);
extern s32 func_0040EAE0(S *, S *);
extern s32 func_00412620(S *, S *);
s32 func_00410AF8(S *a, S *m, u64 k, S *r) {
    s32 n = m->n;
    s32 n2 = n * 2;
    s32 an, cnt, i, res, c;
    u64 *d;
    an = a->n;
    if (r->cap < n2 + 3) {
        res = func_004105C0(n2 + 3, r);
        if (res != 0) {
            return res;
        }
    }
    d = r->d;
    func_00403308(d, 0, n * 16 + 24);
    cnt = an - 1;
    r->n = 1;
    for (i = 0; i < cnt;) {
        func_00412DD8(a->d[i], a, i + 1, a->n - i - 1, r, i * 2 + 1);
        i++;
    }
    res = func_00412D00(n2, r);
    if (res != 0) {
        return res;
    }
    res = func_00412A38(1, r);
    if (res != 0) {
        return res;
    }
    func_00412FB8(a, r);
    for (i = 0; i < n; i++) {
        func_00412DD8(func_0012FE48(d[i], k), m, 0, n, r, i);
    }
    r->n = n2 + 1;
    func_00412BB0(n, r);
    func_00412D00(n, r);
    c = func_0040EAE0(m, r);
    if (c < 0) {
        res = func_00412620(m, r);
        if (res != 0) {
            return res;
        }
    } else if (c == 0) {
        r->d[0] = 0;
        r->n = 1;
    }
    return 0;
}
