/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct Obj Obj;
typedef struct { char _p0[0x44]; s32 (*f44)(Obj *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32); } Vt;
struct Obj { Vt *vt; };
s32 func_01EEC794(Obj *o, s32 a1, s32 a2, s32 a3, s32 a4, f32 x0, f32 x1, f32 x2, f32 x3, f32 x4) {
    return o->vt->f44(o, a1, a2, a3, 1, 0, 0, a4, x0, x1, x3, x4, x2);
}
