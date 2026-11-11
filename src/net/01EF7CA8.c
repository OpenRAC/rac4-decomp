/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char f0[0xc4]; s32 fC4; s32 fC8; } Type1;
/* Advance and return the circular position. */
s32 func_01EF7CA8(Type1 *p, u32 delta)
{
    s32 capacity = p->fC4;
    s32 position = p->fC8;
    position = (s32)((u32)position + (u32)capacity + delta);
    position %= capacity;
    p->fC8 = position;
    return p->fC8;
}
