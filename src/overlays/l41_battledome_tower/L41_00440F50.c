/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

extern void *D_00385F68;

/* For selector eight, store 40 and return the PAL data address. */
int func_L41_00440F50(int a1, int a2, u32 *a3)
{
    if (a2 != 12)
        return 0;
    *a3 = 40;
    return (unsigned int)&D_00385F68;
}
