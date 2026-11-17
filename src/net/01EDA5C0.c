/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; u16 f4; s32 f8; char fC[1]; } Obj;
extern s32 func_01EAA130(s32, s32, void *, s32);
extern s32 func_01EAA218(s32, s32, void *);
s32 func_01EDA5C0(s32 a, s32 b, Obj *o) {
    if (func_01EAA130(a, b, &o->f0, 4) == 0) {
        return -0x15;
    }
    if (func_01EAA130(a, b, &o->f4, 2) == 0) {
        return -0x15;
    }
    if (func_01EAA130(a, b, &o->f8, 4) == 0) {
        return -0x15;
    }
    return func_01EAA218(a, b, o->fC) != 0 ? 0 : -0x15;
}
