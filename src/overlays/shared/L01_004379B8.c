/* cflags: @ee29 -O2 -G8 -ffast-math -Wuninitialized */
#include "common.h"
extern char D_00221468;

/* Return the address and write its size only when the second argument is zero. */
void *func_L01_004379B8(long a1, long a2, int *a3)
{
    if (a2) return 0;
    *a3 = 4;
    return &D_00221468;
}
