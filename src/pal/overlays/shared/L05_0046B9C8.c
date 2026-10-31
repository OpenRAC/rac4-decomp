/* cflags: @ee29 -O2 -G0 -ffast-math -Wuninitialized */
#include "common.h"

extern int func_L05_00468570(unsigned int, unsigned int, int, unsigned int);

/* Call the PAL helper only when the pointer reached through offset 0x18 is nonzero. */
int func_L05_0046B9C8(int a1, int a2, int a3)
{
    int value = *(int *)(*(unsigned int *)(a1 + 24) + 12020);

    if (value)
        value = func_L05_00468570(*(int *)(value + 688), a1 + 64, a3, *(int *)(a1 + 48));
    return value;
}
