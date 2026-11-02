#include "common.h"

typedef struct Type1 {
    f32 f0, f4, f8, fC, f10, f14, f18, f1C, f20;
} Type1;

/* Evaluate the four components, optionally including their velocity. */
void func_004A1AB0(Type1 *p, f32 *a, f32 *b, f32 *c, f32 *d, s32 mode)
{
    *a = p->f4;
    *b = p->f8;
    *c = p->fC;
    *d = p->f10;
    if (!mode) {
        f32 t = p->f0;
        if (t != 0.0f) {
            *a += p->f14 * t;
            *b += p->f18 * p->f0;
            *c += p->f1C * p->f0;
            *d += p->f20 * p->f0;
        }
    }
}
