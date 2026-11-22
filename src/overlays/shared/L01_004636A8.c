#include "common.h"
typedef struct S { char _p0[0x14]; s16 f14; } S;
typedef struct O { char _p0[0x20]; u8 f20; char _p21[2]; u8 f23; char _p24[0xAC - 0x24]; S *fAC; } O;
extern s32 func_00453508(void *);
extern void func_0046BDD0(O *);
extern void func_00473A88(O *, s32, s32);
extern void func_L01_00463540(O *);
void func_L01_004636A8(O *o) {
    S *s = o->fAC;
    switch (o->f20) {
    case 0:
        func_00473A88(o, 1, -1);
        break;
    case 1:
        func_L01_00463540(o);
        if (func_00453508((char *)s + 0x16) != 0) {
            o->f23 = (s32)((f32)s->f14 / 15.0f * 127.0f);
        }
        if (func_00453508((char *)s + 0x14) != 0) {
            func_00473A88(o, 2, -1);
        }
        break;
    case 2:
        func_0046BDD0(o);
        break;
    }
}
