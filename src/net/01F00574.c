/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct { char _p0[8]; s32 f8; } Ctx;
typedef struct { char _p0[0x10]; s32 f10; } Sub;
typedef struct {
    char _p0[0x80];
    Ctx *f80;
    char _p84[0x4C];
    s32 fD0;
    char _pD4[4];
    Sub *fD8;
    char _pDC[0x14];
    s32 fF0;
    char _pF4[0x8C];
    s32 f180;
} Obj;
extern void func_01F004CC(Obj *);
extern void func_01EF0B14(s32, s32);
s32 func_01EF0550(s32, s32);
void func_01F00574(Obj *o) {
    func_01F004CC(o);
    func_01EF0550(o->f80->f8, o->fD0);
    if (o->fF0 != 0) {
        func_01EF0550(o->f80->f8, o->fF0);
    }
    if (o->fD8 != 0) {
        if (o->fD8->f10 != 0) {
            func_01EF0550(o->f80->f8, o->fD8->f10);
        }
        func_01EF0550(o->f80->f8, (s32)o->fD8);
    }
    if (o->f180 != 0) {
        func_01EF0B14(o->f180, 3);
    }
}
