/* cflags: @ee29 -O2 -G8 -ffast-math -Wuninitialized */
#include "common.h"

extern char D_00220D58;

/* Return the data address and its size for selector zero. */
void *func_L01_003D7D88(long a1, long a2, int *a3)
{
    if (a2)
        return 0;
    *a3 = 4;
    return &D_00220D58;
}
