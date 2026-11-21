/* cflags: @ee296 -O2 -G0 */
#include "common.h"
typedef struct { s32 a; s32 n; u64 *d; } Big;
s32 func_0040EAE0(Big *x, Big *y) {
    s32 n = x->n;
    s32 i;
    u64 *a = x->d;
    s32 r = (y->n < n) ? 1 : -1;
    u64 *b = y->d;
    if (n != y->n) return r;
    for (i = n - 1; i >= 0 && a[i] == b[i]; i--);
    if (i < 0) return 0;
    return (a[i] > b[i]) ? 1 : -1;
}
