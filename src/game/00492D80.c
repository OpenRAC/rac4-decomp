#include "common.h"
typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct {
    u128 q;
    s32 f10;
    s32 f14;
    f32 f18;
    f32 f1C;
} Type2;

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    s32 f4;
    u8 f8;
    u8 f9;
    u8 fA;
    u8 fB;
    f32 fC;
    union {
        u128 q;
        f32 f[4];
    } f10;
    Type2 f20;
} Type1;

extern f32 func_004725D8(f32 a0, f32 a1);
extern void *func_00490968(s32);
extern u8 *D_002709A4[];

Type1 *func_00492D80(u128 *a0, u128 *a1, s32 a2, s32 a3) {
    Type1 *p = func_00490968(0x23);
    if (p != 0) {
        Type2 *s;
        p->f10.q = *a0;
        p->f1 = 0;
        s = &p->f20;
        p->f4 = 0x80808080;
        p->f9 = 0x12;
        p->f3 = 0x44;
        p->fC = func_004725D8(10500.0f, 16800.0f);
        p->f2 = *D_002709A4[0];
        s->q = *a1;
        s->f14 = a3;
        s->f10 = a2;
        s->f18 = p->f10.f[2];
        if (a2 == 2) {
            s->f18 = 0.0f;
        }
        s->f1C = func_004725D8(0.0029166667f, 0.005f);
    }
    return p;
}
