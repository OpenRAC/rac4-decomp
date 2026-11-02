/* cflags: @ee29 -O2 -G8 -ffast-math -Wuninitialized */
#include "common.h"
extern char D_002226B0;

/* Return the address and write its size only when the second argument is zero. */
void *func_L01_004FF3D0(long a1, long a2, int *a3)
{
    if (a2) return 0;
    *a3 = 4;
    return &D_002226B0;
}
