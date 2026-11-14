/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; u16 f10; char f12[1]; } Obj;
extern s32 func_01EAA130(s32, s32, void *, s32);
extern s32 func_01EAA218(s32, s32, void *);
s32 func_01EDA4F8(s32 a, s32 b, Obj *o) {
    if (func_01EAA130(a, b, &o->f0, 4) == 0) {
        return -0x15;
    }
    if (func_01EAA130(a, b, &o->f8, 4) == 0) {
        return -0x15;
    }
    if (func_01EAA130(a, b, &o->f4, 4) == 0) {
        return -0x15;
    }
    if (func_01EAA130(a, b, &o->fC, 4) == 0) {
        return -0x15;
    }
    if (func_01EAA130(a, b, &o->f10, 2) == 0) {
        return -0x15;
    }
    return func_01EAA218(a, b, o->f12) != 0 ? 0 : -0x15;
}
