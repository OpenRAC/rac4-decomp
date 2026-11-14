/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct In { void (*f0)(struct In *); } In;
typedef struct { char _p0[0x14]; char f14[0x14]; In *f28; } Obj;
void func_003FD4D8(void *);
extern s32 func_00403440(void *);
void func_003FE7F0(Obj *);
void func_003FE538(Obj *o) {
    func_003FD4D8(o->f14);
    if (o->f28 != 0) {
        o->f28->f0(o->f28);
        func_00403440(o->f28);
    }
    func_003FE7F0(o);
}
