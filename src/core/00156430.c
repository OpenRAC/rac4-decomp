/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct Obj Obj;
typedef struct { char _p[0x28]; void (*print)(Obj *, char *); } Vt;
struct Obj { char _p[0x10]; Vt *vt; };
extern char D_0019C310[];
extern char D_0019C320[];
void func_0011D920(char *, char *, s32);
void func_00156430(Obj *o, s32 x) {
    char buf[0x80];
    o->vt->print(o, D_0019C310);
    func_0011D920(buf, D_0019C320, x);
    o->vt->print(o, buf);
    o->vt->print(o, D_0019C310);
}
