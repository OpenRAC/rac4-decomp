#include "common.h"

extern u8 *func_00490968(s32);
typedef int s128_00462FD0 __attribute__((mode(TI)));
typedef struct {
    s128_00462FD0 v;
    s32 f10;
    s32 f14;
    s16 f18;
    s16 f1A;
    f32 f1C;
} Sub_00462FD0;
typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    s32 f4;
    u8 f8;
    u8 f9;
    s16 fA;
    f32 fC;
    s128_00462FD0 f10;
    Sub_00462FD0 sub;
} Part_00462FD0;
extern u8 *D_0027096C[];
extern u8 func_001633D0(void);

/* from rac3-decomp's func_L01_00466588 */
Part_00462FD0 *func_00492150(s128_00462FD0 *pos, s128_00462FD0 *v2, s32 a2, s32 a3, s32 t0, s32 t1, f32 f) {
    Part_00462FD0 *p;
    Sub_00462FD0 *q;
    if (t0 == 0) {
        return 0;
    }
    p = ((Part_00462FD0 * (*)(s32))func_00490968)(21);
    if (p != 0) {
        p->f10 = *pos;
        p->f4 = a2;
        p->f1 = 0;
        p->fC = f;
        p->f9 = 164;
        p->f3 = 72;
        p->f8 = func_001633D0();
        p->f2 = *D_0027096C[0];
        q = &p->sub;
        p->fA = t0;
        q->f18 = t0;
        q->f1C = f;
        q->f10 = a2;
        q->f14 = a3;
        q->f1A = t1;
        q->v = *v2;
    }
    return p;
}
