/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern u8 D_0016FD20[];
extern s32 func_0015DB88(void *);
/* Install the table and conditionally dispatch. */
void func_00156390(u8 **p, s32 flags)
{
    *p = D_0016FD20;
    if (flags & 1) func_0015DB88(p);
}
