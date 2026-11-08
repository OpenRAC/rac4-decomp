/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type2 {
    u16 f0;
    u8 pad2[6];
} Type2;

typedef struct Type1 {
    Type2 *f0;
    u16 f4;
    u16 f6;
} Type1;

s32 func_01EDA990(Type1 *arg0)
{
    s32 mask = 0;
    s32 i;

    for (i = 0; i < arg0->f6; i++) {
        mask |= 1 << arg0->f0[i].f0;
    }
    return mask;
}
