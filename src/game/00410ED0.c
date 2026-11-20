/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 cap; s32 n; u64 *d; } S;
extern s32 func_004105C0(s32, S *);
extern void func_00403308(void *, s32, s32);
extern void func_00412DD8(u64, S *, s32, s32, S *, s32);
s32 func_00410ED0(S *a, S *b, S *r) {
    s32 bn = b->n;
    s32 an = a->n;
    s32 tot = bn + an;
    s32 i;
    s32 rc;
    u64 *d;
    if (r->cap < tot) {
        rc = func_004105C0(tot, r);
        if (rc != 0) {
            return rc;
        }
    }
    d = r->d;
    func_00403308(d, 0, tot * 8);
    for (i = 0; i < an; i++) {
        func_00412DD8(a->d[i], b, 0, bn, r, i);
    }
    while (tot > 0 && d[--tot] == 0) {
    }
    tot++;
    r->n = tot;
    return 0;
}
