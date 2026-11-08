/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern u8 D_0016FF28[];
extern s32 func_01EF3690(void *);
/* Install the table and conditionally dispatch. */
void func_00156600(u8 **p, s32 flags)
{
    *p = D_0016FF28;
    if (flags & 1) func_01EF3690(p);
}
