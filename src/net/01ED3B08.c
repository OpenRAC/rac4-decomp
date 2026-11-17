/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0, f4; char _p8[0xF8]; } Ent;
typedef struct { s32 f0; u32 f4; s32 f8, fC; Ent e[64]; } Obj;
void func_01ED3B08(Obj *o) {
    u32 i;
    o->f0 = 1;
    o->f4 = 0xFFFFFF;
    o->f8 = 0;
    o->fC = 0;
    for (i = 0; i < 64; i++) {
        o->e[i].f0 = 0;
        o->e[i].f4 = 0;
    }
}
