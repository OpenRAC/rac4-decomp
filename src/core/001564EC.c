/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern u8 D_0016FE18[];
extern s32 func_0015DB88(void *);
/* Install the table and conditionally dispatch. */
void func_001564EC(char *p, s32 flags)
{
    *(u8 **)(p + 0xd8) = D_0016FE18;
    if (flags & 1) func_0015DB88(p);
}
