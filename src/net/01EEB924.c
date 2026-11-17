/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct In In;
typedef struct { char _p0[0x34]; void (*f34)(In *, s32); } Vt;
struct In { char _p0[8]; Vt *f8; };
typedef struct { char _p0[0x18]; s32 f18; char _p1c[4]; In *f20; } Obj;
void func_01EEB924(Obj *o) {
    In *p = o->f20;
    if (p != 0 && o->f18 != 0) {
        o->f18 = 0;
        p->f8->f34(p, 0);
    }
}
