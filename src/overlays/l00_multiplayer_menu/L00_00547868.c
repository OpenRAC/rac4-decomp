/* cflags: @ee29 -O2 -G0 */
#include "common.h"

u64 func_L00_00539520(u64 *, u64 *, s32, u64);
u64 func_L00_00539898(u64 *, u64 *, s32, u64);
void func_L00_00539C00(u64 *, u64 *, s32);
void func_L00_00539E30(u64 *, u64 *, u64 *, s32);

void func_L00_00547868(u64 *r, u64 *a, s32 n, u64 *t) {
    s32 m;
    u64 *ap;
    u64 *rp;
    s32 i;
    s32 nn;

    nn = n * 2;
    ap = a;
    rp = r + 1;
    m = n - 1;
    r[nn - 1] = 0;
    r[0] = 0;
    if (m > 0) {
        ap = a + 1;
        rp[m] = func_L00_00539898(rp, ap, m, a[0]);
        rp = r + 3;
    }
    for (i = n - 2; i > 0; i--) {
        u64 w = *ap;
        m--;
        ap++;
        rp[m] = func_L00_00539520(rp, ap, m, w);
        rp += 2;
    }
    func_L00_00539E30(r, r, r, nn);
    func_L00_00539C00(t, a, n);
    func_L00_00539E30(r, r, t, nn);
}
