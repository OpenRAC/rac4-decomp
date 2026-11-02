/* cflags: @ee29 -O2 -G8 -ffast-math -Wuninitialized */
#include "common.h"

extern char D_00221220;

/* Return the data address and size for selector zero. */
void *func_L05_0042EA90(long a1, long a2, int *a3)
{
    if (a2)
        return 0;
    *a3 = 12;
    return &D_00221220;
}
