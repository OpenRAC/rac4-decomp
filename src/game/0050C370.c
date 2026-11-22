#include "common.h"

typedef struct {
    char p0[0xC];
    u32 fC;
    char p10[4];
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
} Src;

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
} Dst;

void func_0050C370(Src *s, f32 *p, Dst *d, s32 flag) {
    f32 t;
    f32 x;
    f32 x2;
    u32 h;
    u32 v;
    x = p[0] + s->f14;
    d->f0 = x;
    d->f4 = p[1] + s->f18;
    x2 = x + s->f1C;
    d->f8 = x2;
    d->fC = d->f4 + s->f20;
    d->f10 = 0.0f;
    d->f14 = 0.0f;
    if (flag) {
        h = (s->fC >> 9) & 3;
        v = (s->fC >> 11) & 3;
        if (h != 2) {
            if (h == 3) {
                t = s->f1C * 0.5f;
                d->f0 = x - t;
                d->f8 = x2 - t;
                d->f10 = -t;
            }
        } else {
            d->f0 = x - s->f1C;
            d->f8 = x2 - s->f1C;
            d->f10 = -s->f1C;
        }
        if (v != 2) {
            if (v == 3) {
                t = s->f20 * 0.5f;
                d->f4 = d->f4 - t;
                d->fC = d->fC - t;
                d->f14 = -t;
            }
        } else {
            d->f4 = d->f4 - s->f20;
            d->fC = d->fC - s->f20;
            d->f14 = -s->f20;
        }
    }
}
