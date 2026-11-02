/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

extern void *D_00386F20;

/* For selector eight, store 208 and return the PAL data address. */
int func_L41_0046ECC0(int a1, int a2, u32 *a3)
{
    if (a2 != 6)
        return 0;
    *a3 = 208;
    return (unsigned int)&D_00386F20;
}
