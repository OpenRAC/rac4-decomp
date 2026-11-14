/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x14]; char f14[0x18]; s32 f2C; } Obj;
s32 func_003FF868(Obj *);
void func_003FD4D8(void *);
void func_003FE7F0(Obj *);
extern s32 func_00403440(void *);
void func_003FF788(Obj **pp) {
    Obj *o = *pp;
    if (o == 0) {
        return;
    }
    if (func_003FF868(o) != 0) {
        *pp = 0;
        return;
    }
    o->f2C = 0;
    func_003FD4D8(o->f14);
    func_003FE7F0(o);
    func_00403440(o);
    *pp = 0;
}
