/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct { s32 f0[10]; s32 f28; } Obj;
void func_01F04BF0(s32);
void func_01F04E28(Obj *o) {
    s32 i;
    for (i = 0; i < o->f28; i++) {
        func_01F04BF0(o->f0[i]);
    }
}
