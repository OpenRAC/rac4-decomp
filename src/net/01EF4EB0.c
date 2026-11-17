/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct Obj Obj;
typedef struct {
    char _p0[0x10];
    s32 (*f10)(Obj *, s32, s32, s32);
    s32 (*f14)(Obj *, s32, s32, s32);
    char _p18[0x24];
    s32 (*f3C)(Obj *);
} Vt;
struct Obj { char _p0[8]; Vt *vt; };
s32 func_01EF4EB0(Obj *o, s32 a, s32 b, s32 c) {
    if (o->vt->f3C(o)) {
        return o->vt->f14(o, a, b, c);
    }
    return o->vt->f10(o, a, b, c);
}
