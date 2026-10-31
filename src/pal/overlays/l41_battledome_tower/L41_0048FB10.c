/* cflags: @ee29 -O2 -G8 -ffast-math -Wuninitialized */
#include "common.h"

extern char D_00222240;

/* Return the address and its size only for selector zero. */
void *func_L41_0048FB10(long a1, long a2, int *a3)
{
    if (a2)
        return 0;
    *a3 = 4;
    return &D_00222240;
}
