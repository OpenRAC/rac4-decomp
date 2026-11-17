/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct X X;
typedef struct { char _p0[0x14]; void (*f14)(X *, s32, s32, s32, s32); } Vt;
struct X { Vt *vt; };
typedef struct { char _p0[0x2C]; s32 f2C; char _p30[0x8670]; s32 f86A0; char _p86a4[0x418]; X *f8ABC; s32 f8AC0; } Obj;
void func_01EEAAA4(Obj *o, s32 a1, s32 a2, s32 a3) {
    o->f86A0 = 0;
    o->f2C += a3;
    o->f8ABC->vt->f14(o->f8ABC, o->f8AC0, a1, a2, a3);
}
