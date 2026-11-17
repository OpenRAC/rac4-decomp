/* cflags: @ee296 -Os -G0 */
#include "common.h"

typedef struct { void *f0; s32 f4; char _p8[8]; void (*f10)(s32); void *f14; char _p18[0x28]; void *f40; } Obj;
extern void (*D_0016AC6C)(void *);
extern void func_01EE407C(void *);
void func_01EE4D48(Obj *o) {
    if (o->f10 != 0) {
        o->f10(o->f4);
    }
    if (o->f14 != 0) {
        D_0016AC6C(o->f14);
    }
    if (o->f40 != 0) {
        D_0016AC6C(o->f40);
    }
    if (o->f0 != 0) {
        func_01EE407C(o->f0);
        return;
    }
    D_0016AC6C(o);
}
