/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern u8 D_0016FF60[];
extern void func_01EF3748(void *);
/* Install the table and conditionally dispatch. */
void func_00156688(char *p, s32 flags)
{
    *(u8 **)(p + 0xb0) = D_0016FF60;
    if (flags & 1) func_01EF3748(p);
}
