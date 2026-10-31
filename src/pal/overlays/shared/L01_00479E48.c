/* cflags: @ee29 -O2 -G8 -ffast-math -Wuninitialized */
#include "common.h"

extern char D_00221A88[8];

/* Return the eight-byte object for index zero. */
void *func_L01_00479E48(long a1, long a2, int *a3)
{
    if (a2)
        return 0;
    *a3 = 8;
    return D_00221A88;
}
