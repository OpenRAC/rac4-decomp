#include "common.h"

typedef struct Obj Obj;
struct Obj { char _p[4]; u32 f4; char _p8[4]; s32 fC; char _p10[0x22]; u8 f32; u8 f33; char _p34; u8 f35; char _p36[0x32]; f32 f68; void (*f6C)(s32, s32); };
Obj *func_004765F0(s32);
void func_00481100(s32, s32, s32);
s32 func_00480FB8(s32 a, s32 lvl, void (*cb)(s32, s32), s32 fa, s32 fc, s32 fb, f32 f) {
    Obj *o = func_004765F0(a);
    if (o == 0) {
        return 0;
    }
    if (o->f4 & 0x80) {
        return 0;
    }
    if (o->f33 == lvl) {
        return 1;
    }
    if (fa == 0 && o->f32 != 0) {
        return 0;
    }
    if (lvl >= 33) {
        return 0;
    }
    if (o->f33 != 0) {
        func_00481100(a, o->f33, 0);
    }
    o->f33 = lvl;
    o->f6C = cb;
    o->f68 = f;
    o->f4 &= ~0x40000;
    o->fC = 1;
    if (fb != 0) {
        o->f35 = 0;
    }
    if (fa != 0) {
        o->f4 |= 0x80;
    }
    if (fc != 0) {
        o->f4 |= 0x20000;
    }
    if (o->f6C != 0) {
        o->f6C(a, 0);
    }
    return 1;
}
