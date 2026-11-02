/* cflags: @ee29 -O2 -G8 -ffast-math -Wuninitialized */
#include "common.h"

extern char D_00221200;

/* Return the data address and size for selector zero. */
void *func_L01_00426D18(long a1, long a2, int *a3)
{
    if (a2)
        return 0;
    *a3 = 12;
    return &D_00221200;
}
