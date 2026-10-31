/* cflags: @ee29 -O2 -G8 -ffast-math -Wuninitialized */
#include "common.h"

extern char D_002212B0;

/* Return the data address and size for selector zero. */
void *func_L01_00427990(long a1, long a2, int *a3)
{
    if (a2)
        return 0;
    *a3 = 12;
    return &D_002212B0;
}
