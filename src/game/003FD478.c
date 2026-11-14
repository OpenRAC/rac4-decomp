/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Obj { char _p0[0x30]; void *f30; struct Obj *f34; } Obj;
void *func_004033B0(s32);
void func_003FE500(Obj *);
extern char D_003CBCCC[];
s32 func_003FD478(Obj **pp) {
    Obj *o = func_004033B0(0x38);
    *pp = o;
    if (o == 0) {
        return 0x206;
    }
    func_003FE500(o);
    o->f34 = o;
    o->f30 = D_003CBCCC;
    return 0;
}
