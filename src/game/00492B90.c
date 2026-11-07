#include "common.h"
typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct {
    f32 x, y, z;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
} Type2;

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    s32 f4;
    s8 f8;
    u8 f9;
    s16 fA;
    f32 fC;
    u128 f10;
    Type2 f20;
} Type1;

extern s32 func_00472590(s32 a0, s32 a1);
extern f32 func_004725D8(f32 a0, f32 a1);
extern f32 func_00472690(void);
extern f32 func_004746C8(u128 a0, s32 a1);
extern void *func_00490968(s32);
extern s32 D_0021EDD4;
extern u8 *D_002709A0[];
extern void *D_003367B8[];

Type1 *func_00492B90(u128 *a0, f32 *a1, s32 a2, f32 f0, f32 f1) {
    Type1 *p = func_00490968(0x22);
    if (p != 0) {
        Type2 *s;
        p->f4 = a2;
        p->f1 = 0;
        s = &p->f20;
        p->f9 = 0x44;
        p->f3 = 0x44;
        s->fC = func_004725D8(0.75f, 1.25f) * f0;
        p->fC = 5250.0f;
        p->f8 = func_00472590(-10, 10) - 0x80;
        p->f2 = *D_002709A0[0];
        p->fA = func_00472590(70, 140);
        if (f1 == -1.0f) {
            if (D_0021EDD4 == 0) {
                void **q;
                void *e;
                s32 i;
                s32 t;
                q = D_003367B8;
                e = *q;
                t = 0x30;
                i = 9;
                do {
                    if (e != 0) {
                        if (*(s32 *)((u8 *)e + 0x25CC) == t) {
                            s->f10 = *(f32 *)((u8 *)e + 0xA8) + 0.4f;
                        } else {
                            s->f10 = *(f32 *)((u8 *)e + 0x2E0);
                        }
                    }
                    q++;
                    i--;
                    e = *q;
                } while (i >= 0);
            } else {
                s->f10 = func_004746C8(*a0, 0);
            }
        } else {
            s->f10 = f1;
        }
        s->f14 = func_00472690();
        s->f18 = func_004725D8(0.0290888231f, 0.116355292f);
        s->f1C = func_004725D8(0.00833333377f, 0.0233333334f);
        s->x = a1[0];
        s->y = a1[1];
        s->z = a1[2];
        p->f10 = *a0;
    }
    return p;
}
