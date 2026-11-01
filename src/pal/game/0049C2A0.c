#include "common.h"

typedef struct Type1 {
    f32 f0, f4, f8, fC, f10, f14, f18, f1C, f20;
} Type1;
/* Update the value vector and optional deltas from its previous values. */
void func_0049C2A0(Type1 *p, s32 deltas, f32 a, f32 b, f32 c, f32 d)
{
    if (deltas) {
        p->f4 = a - p->f14;
        p->f8 = b - p->f18;
        p->fC = c - p->f1C;
        p->f10 = d - p->f20;
        p->f0 = 1.0f;
    } else {
        p->f4 = 0;
        p->f8 = 0;
        p->fC = 0;
        p->f10 = 0;
        p->f0 = 0;
    }
    p->f14 = a;
    p->f18 = b;
    p->f1C = c;
    p->f20 = d;
}
