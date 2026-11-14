/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { void *f0; void *f4; void *f8; void *fC; void *f10; char _p14[0x50]; } Ctx;
extern Ctx *func_01EE3DB0(void *, u32);
extern void *func_0011A518(void *, s32, u32);
Ctx *func_01EE40B8(void *pool, void *a, void *b, void *c, void *d) {
    Ctx *x = func_01EE3DB0(pool, sizeof(Ctx));
    if (x == 0) {
        return 0;
    }
    func_0011A518(x, 0, sizeof(Ctx));
    x->f0 = pool;
    x->f4 = a;
    x->f8 = b;
    x->fC = c;
    x->f10 = d;
    return x;
}
