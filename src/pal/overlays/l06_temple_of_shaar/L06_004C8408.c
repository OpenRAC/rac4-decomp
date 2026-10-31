/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

extern void *D_003A4EA0;

/* For selector eight, store 36 and return the PAL data address. */
int func_L06_004C8408(int a1, int a2, u32 *a3)
{
    if (a2 != 8)
        return 0;
    *a3 = 36;
    return (unsigned int)&D_003A4EA0;
}
