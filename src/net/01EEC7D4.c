/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct Obj Obj;
typedef struct { char _p0[0x1C]; void (*f1C)(Obj *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32); } Vt;
struct Obj { Vt *vt; };
void func_01EEC7D4(Obj *o, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10) {
    o->vt->f1C(o, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, 1);
}
