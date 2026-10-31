/* cflags: @ee29 -O2 -G8 -ffast-math -Wuninitialized */
#include "common.h"

extern char D_002212D0;

/* For selector zero, store 12 and return the PAL data address. */
void *func_L05_0042F758(long a1, long a2, int *a3)
{
    if (a2) return 0;
    *a3 = 12;
    return &D_002212D0;
}
