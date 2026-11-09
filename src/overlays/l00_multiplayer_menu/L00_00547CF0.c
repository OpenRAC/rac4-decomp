/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern u64 func_0012FE48(u64, u64);
u64 func_L00_00539520(u64 *, u64 *, s32, u64);
void func_L00_00539F10(u64 *, u64 *, u64 *, s32);

/* Montgomery reduction of a (2n words) by modulus m into r */
void func_L00_00547CF0(u64 *r, u64 *a, u64 *m, s32 n, u64 n0) {
    u64 *hi;
    u64 c;
    u64 v;
    u64 t;
    s32 i;

    hi = a + n;
    c = 0;
    for (i = 0; i < n; i++) {
        v = func_L00_00539520(a, m, n, func_0012FE48(*a, n0));
        a++;
        v += c;
        c = v < c;
        t = *hi + v;
        c += t < v;
        *hi = t;
        hi++;
    }
    i = n - 1;
    if (c == 0) {
        if (a[i] == m[i] && i > 0) {
            do {
                i--;
            } while (i > 0 && a[i] == m[i]);
        }
        c = a[i] >= m[i];
    }
    if (c) {
        func_L00_00539F10(r, a, m, n);
        return;
    }
    for (i = 0; i < n; i++) {
        r[i] = a[i];
    }
}
