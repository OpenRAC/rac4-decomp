/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

extern void *D_003A2D00;

/* For selector eight, store 208 and return the PAL data address. */
int func_L05_004644C8(int a1, int a2, u32 *a3)
{
    if (a2 != 6)
        return 0;
    *a3 = 208;
    return (unsigned int)&D_003A2D00;
}
