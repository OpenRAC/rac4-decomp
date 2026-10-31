/* cflags: @ee29 -O2 -G8 -ffast-math -Wuninitialized */
#include "common.h"
extern char D_00222760[4];

/* Return the table and its count for selector zero. */
void *func_L01_00501420(long a1, long a2, int *a3)
{
    if (a2) return 0;
    *a3 = 4;
    return D_00222760;
}
