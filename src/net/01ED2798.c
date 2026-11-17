/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u32 f0; char _p4[0x88]; u16 *f8C; } E;
typedef struct { char _p0[0x404]; u32 f404; } Obj;
E *func_01ED2458(Obj *);
s32 func_01ED2798(Obj *o, u16 v) {
    E *e;
    if (o == 0) {
        return 0x17;
    }
    e = func_01ED2458(o);
    if (e == 0) {
        return 0x17;
    }
    if (o->f404 >= e->f0) {
        return 0x17;
    }
    e->f8C[o->f404] = v;
    return 0;
}
