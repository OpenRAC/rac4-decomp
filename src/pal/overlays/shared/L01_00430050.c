/* cflags: @ee29 -O2 -G8 -ffast-math -Wuninitialized */
#include "common.h"

extern char D_00221440;

/* Return the table address and its size for the first selector. */
void *func_L01_00430050(long a1, long a2, int *a3)
{
    if (a2)
        return 0;
    *a3 = 4;
    return &D_00221440;
}
