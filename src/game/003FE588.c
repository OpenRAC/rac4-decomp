/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; } In;
typedef struct { char _p0[0x28]; In *f28; } Obj;
s32 func_003FE588(Obj *o, s32 v) {
    In *p = o->f28;
    if (p == 0) {
        return 0x203;
    }
    return p->f0 == v ? 0 : 0x205;
}
