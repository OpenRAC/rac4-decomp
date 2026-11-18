/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct Obj Obj;
typedef struct { char _p0[0x48]; s32 (*f48)(Obj *); } Vt;
struct Obj { char _p0[8]; Vt *vt; };
extern char D_0019C8C0[];
extern void func_01F0C090(const char *, s32);
extern Obj *func_01EF58C4(s32, void *);
extern void func_01EF4E64(Obj *, void *);
Obj *func_01EF4DDC(void *arg) {
    Obj *o = func_01EF58C4(0xA0, arg);
    func_01EF4E64(o, arg);
    if (o == 0) {
        func_01F0C090(D_0019C8C0, 0x2F);
    }
    if (o->vt->f48(o)) {
        func_01F0C090(D_0019C8C0, 0x30);
    }
    return o;
}
