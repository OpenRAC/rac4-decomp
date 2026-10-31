/* cflags: @ee29 -O2 -G8 -ffast-math -Wuninitialized */
#include "common.h"

extern unsigned char D_00221D78[8];

/* Returns the eight-byte object only for selector zero. */
void *func_L01_0049C018(long a1, long a2, int *a3)
{
    if (a2)
        return 0;
    *a3 = 8;
    return D_00221D78;
}
