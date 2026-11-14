#include "common.h"

typedef struct { char _p0[0xC4]; s32 fC4; char _pc8[0x24]; u32 fEC, fF0, fF4, fF8; } X;
typedef struct { char _p0[0x40]; X *f40; } Obj;
void func_001418E8(Obj *);
void func_00142150(Obj *o, u32 a1, s32 a2) {
    X *x = o->f40;
    x->fC4 = 1;
    x->fEC = (a1 & 0x0FFFFFFF) | 0x20000000;
    x->fF8 = a2;
    x->fF4 = 0;
    x->fF0 = 0;
    func_001418E8(o);
}
