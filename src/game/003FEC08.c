/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 a, b; } P;
void func_003FEC70(P *);
void func_003FEC08(P *p) {
    P *hi;
    func_003FEC70(p);
    for (hi = p + 15; p < hi; p++, hi--) {
        s32 t = p->a;
        p->a = hi->a;
        hi->a = t;
        t = p->b;
        p->b = hi->b;
        hi->b = t;
    }
}
