/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0xC]; s32 fC; } Obj;
typedef struct { char _p0[4]; s32 (*f4)(s32 *, Obj *); } Ops;
extern s32 func_003FE788(Obj *);
extern s32 func_003FE6F0(Obj *, Ops *, s32);
s32 func_00408490(Obj *o, s32 *k, Ops *ops) {
    s32 r;
    if (o == 0) {
        return 0x212;
    }
    if (o->fC == 0) {
        return 0x211;
    }
    r = func_003FE788(o);
    if (r == 0) {
        return r;
    }
    r = ops->f4(k, o);
    if (r != 0) {
        return r;
    }
    return func_003FE6F0(o, ops, *k);
}
