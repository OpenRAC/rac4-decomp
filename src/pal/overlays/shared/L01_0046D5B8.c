#include "common.h"

typedef struct Tgt {
    u8 pad0[0x20];
    u8 x20;
    u8 pad21[0x9B];
    s16 xBC;
} Tgt;

typedef struct V {
    s32 x0;
    s32 x4;
    void *x8;
    void *xC;
    s32 x10;
    s32 x14;
    Tgt *x18;
    u8 *x1C;
} V;

typedef struct Moby {
    u8 pad0[0x10];
    f32 x10[4];
    u8 x20;
    u8 pad21[0x8B];
    V *xAC;
} Moby;

typedef struct G {
    u8 pad0[0x1A0];
    u8 *x1A0;
} G;

extern G D_00298A58;
typedef struct E { s32 x0; } E;
extern E D_00222C50;
extern E D_00222B9C;
extern u8 D_0046E3A8[];

extern void func_00449A28(void *a, void *b, Moby *c);
extern s32 func_00453CE8(s32 *p);
extern void func_00454140(f32 x);
extern void func_00461A80(s32 x);
extern void func_0046C6B0(void *p);
extern void func_0046D258(Tgt *t, s32 a, f32 *out);
extern s32 func_00472E70(s32 a, s32 b);
extern void func_00474368(Moby *m, s32 a, s32 b);
extern void func_004E2F98(s32 a, s32 b, Moby *m, s32 c);
extern u8 *func_L00_0061AB40(f32 *a, void *b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, f32 i, f32 j, f32 k);
extern void func_L01_0046D9D0(Moby *m);
extern void func_L01_0046DBB0(Moby *m);
extern void func_L01_0046DD60(Moby *m);
extern void func_L01_0046E148(Moby *m);

// Per-frame update of a timed moby: state 0 starts it, state 3 runs the countdown and spawns effects, state 4 frees it when the timer ends.
void func_L01_0046D5B8(Moby *m) {
    f32 pos[4];
    V *v;
    u8 *p;
    Tgt *t;
    s32 i;
    s32 n;
    s32 c;
    s32 six;

    v = m->xAC;
    if (v->x1C != 0) {
        *v->x1C = 1;
    }
    t = v->x18;
    if (t == 0 || t->x20 == 0xFE || t->x20 == 0xFD || t->xBC != v->x14) {
        *v->x1C = 0;
        v->x4 = 0;
        func_00474368(m, 4, -1);
    } else {
        func_0046D258(t, 0, m->x10);
    }
    switch (m->x20) {
    case 0:
        m->x20 = 3;
        v->x4 = 0x64;
        func_004E2F98(0x2E, 0x100, m, 0x23F7);
        break;
    case 3:
        if ((v->x4 & 7) == 0) {
            func_L01_0046DBB0(m);
        }
        func_00453CE8(&v->x4);
        six = 6;
        func_L01_0046D9D0(m);
        func_0046D258(v->x18, 0, pos);
        for (i = 1; i >= 0; i--) {
            n = (func_00472E70(10, 0x14) * 5 + 2) / six;
            c = func_00472E70(-1, -3);
            p = func_L00_0061AB40(pos, &D_00222C50, n, 0x72E3EC, c, 0x30, 0, 0, 31500.002f, 157500.0f, -0.00040000002f);
            if (p != 0) {
                p[2] = D_00298A58.x1A0[func_00472E70(0, 3)];
            }
        }
        if (v->x4 < 0x22) {
            m->x20 = 4;
        }
        break;
    case 4:
        if (func_00453CE8(&v->x4) != 0 && v->x0 == 0) {
            if (v->x8 != 0) {
                func_0046C6B0(v->x8);
            }
            if (v->xC != 0) {
                func_0046C6B0(v->xC);
            }
            if (v->x10 != -1) {
                func_00461A80(v->x10);
            }
            *v->x1C = 0;
            func_0046C6B0(m);
            return;
        }
        break;
    }
    func_00454140((1.0f - (f32)v->x4 / 100.0f) * 6.2831855f - 3.1415927f);
    func_L01_0046DD60(m);
    func_L01_0046E148(m);
    func_00449A28(&D_00222B9C, D_0046E3A8, m);
}
