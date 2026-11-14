/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x10]; s32 (*f)(s32); } Vt;
typedef struct { char _p0[0xC]; Vt *fC; char _p10[0xC]; s32 f1C; } Obj;
s32 func_00408260(s32);
s32 func_004071B0(Obj *o) {
    s32 r = o->fC->f(o->f1C);
    if (r != 0) {
        return func_00408260(r);
    }
    return 0;
}
