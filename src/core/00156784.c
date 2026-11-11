/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern u8 D_00170078[];
extern void func_01EF5914(void);
/* Install the table and conditionally dispatch. */
void func_00156784(u8 **p, s32 flags)
{
    *p = D_00170078;
    if (flags & 1) func_01EF5914();
}
