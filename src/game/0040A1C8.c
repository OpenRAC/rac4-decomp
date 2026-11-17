/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[8]; s32 (*f8)(s32, s32, s32, s32, s32, s32, s32); } Vt;
typedef struct { char _p0[0x10]; Vt *f10; char _p14[0xC]; s32 f20; } Obj;
s32 func_00408260(s32);
s32 func_0040A1C8(Obj *o, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    s32 r = o->f10->f8(o->f20, a1, a2, a3, a4, a5, a7);
    if (r != 0) {
        return func_00408260(r);
    }
    return 0;
}
