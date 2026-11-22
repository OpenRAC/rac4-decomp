#include "common.h"
typedef struct S {
    char _p0[0xF0]; s32 fF0; s32 fF4; char _p1[0x13C - 0xF8]; s32 f13C;
    char _p2[0x2B1 - 0x140];
    u8 f2B1;
} S;
typedef struct T { char _p[0x10]; s32 f10; char _q[0x10]; f32 f24; } T;
typedef struct O {
    char _p0[0x24]; T *f24; char _p1[0x70 - 0x28]; f32 f70; char _p2[0x98 - 0x74]; s32 f98;
    char _p3[0xAC - 0x9C]; S *fAC;
} O;
extern s32 func_00453508(void *);
extern void func_L01_005ABDE8(void *, f32, f32, f32);
s32 func_L01_004C1BE8(O *o, s32 sel) {
    S *s = o->fAC;
    f32 f;
    switch (sel) {
    case 0:
        o->f98 = 0;
        *(s16 *)((u8 *)s + 0x4A6) = 5;
        s->fF0 |= 0x80;
        s->f2B1 = 0;
        break;
    case 1:
        if (func_00453508((u8 *)s + 0x4A6)) {
            o->f98 = o->f24->f10;
        }
        f = o->f24->f24 * 0.85f;
        if (o->f70 < f) {
            o->f70 += 0.005f;
        } else {
            o->f70 = f;
        }
        func_L01_005ABDE8(o, 0.0f, 20.0f, 32.0f);
        break;
    case 4:
        o->f98 = o->f24->f10;
        o->f70 = o->f24->f24 * 0.85f;
        s->f2B1 = 1;
        s->fF4 |= 0x800;
        s->f13C = 0;
        s->fF0 &= ~0x80;
        break;
    }
    return 1;
}
