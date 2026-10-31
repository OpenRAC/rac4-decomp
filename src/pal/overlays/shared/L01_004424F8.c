/* cflags: @ee29 -O2 -G8 -ffast-math -Wuninitialized */
#include "common.h"

extern char D_00221620;

/* Return an address and size when the second argument is zero. */
void *func_L01_004424F8(long a1, long a2, int *a3)
{
    if (a2)
        return 0;
    *a3 = 8;
    return &D_00221620;
}
