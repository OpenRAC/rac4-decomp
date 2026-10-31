/* cflags: @ee29 -O2 -G8 -ffast-math -Wuninitialized */
#include "common.h"

extern char D_002213F0;

/* Return the shared address and report four bytes for selector zero. */
void *func_L01_0042F708(long a1, long a2, int *a3)
{
    if (a2) return 0;
    *a3 = 4;
    return &D_002213F0;
}
