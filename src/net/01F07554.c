/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct Obj Obj;
typedef struct { char _p[0x1C]; s32 (*f1C)(Obj *, s32); } Vt;
struct Obj { Vt *vt; };
typedef struct { Obj *obj; s32 pad; } Ent;
s32 func_01F07554(Ent *e, s32 arg) {
    s32 r = 1;
    s32 i;
    for (i = 0; i < 8 && r != 0; i++) {
        Obj *o = e->obj;
        e++;
        if (o != 0) {
            r = o->vt->f1C(o, arg);
        }
    }
    return r;
}
