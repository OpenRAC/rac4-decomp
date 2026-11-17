/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0xC]; s32 fC; } Obj;
typedef struct { s32 (*f0)(Obj *, s32); } Ops;
s32 func_00408458(Obj *o, Ops *ops, s32 a2) {
    if (o == 0) {
        return 0x212;
    }
    if (o->fC != 0) {
        return 0x20E;
    }
    return ops->f0(o, a2);
}
