/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct { char _p0[8]; s32 f8[26]; s32 f70[26]; void *fD8; } Obj;
extern char D_0016FE18[];
void func_01EED5EC(Obj *o) {
    u32 i;
    o->fD8 = D_0016FE18;
    for (i = 0; i < 26; i++) {
        o->f70[i] = 0;
        o->f8[i] = 0;
    }
}
