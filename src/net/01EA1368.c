/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x46C]; s32 f46C; } Obj;
extern s32 D_001B1E28[];
s32 func_01EAA898(Obj *, s32, s32, s32, s32, s32);
void func_01EA1368(s32 a0, Obj *o, s32 a2, s32 a3, s32 a4) {
    s32 r = func_01EAA898(o, a0, a2, a3, a4, 0);
    if (o != 0) {
        D_001B1E28[o->f46C] = r;
    }
}
