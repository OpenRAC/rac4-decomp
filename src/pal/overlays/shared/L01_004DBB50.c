/* cflags: @ee29 -O2 -G8 -ffast-math -Wuninitialized */
#include "common.h"
extern char D_00222300[4];

/* Return the data for index zero and report its count. */
void *func_L01_004DBB50(long a1, long a2, int *a3)
{
    if (a2)
        return 0;
    *a3 = 4;
    return D_00222300;
}
