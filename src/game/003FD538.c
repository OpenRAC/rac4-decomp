/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x34]; s32 f34; } Obj;
s32 func_003FD5F8(Obj *);
void func_003FE538(Obj *);
extern s32 func_00403440(void *);
void func_003FD538(Obj **pp) {
    Obj *o = *pp;
    if (func_003FD5F8(o) == 0) {
        o->f34 = 0;
        func_003FE538(o);
        func_00403440(o);
    }
    *pp = 0;
}
