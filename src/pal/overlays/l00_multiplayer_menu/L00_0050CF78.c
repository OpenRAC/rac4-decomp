/* cflags: @ee296 -O2 -G0 */
#include "common.h"

u64 D_0049E688 = 1;
extern u64 func_0012FE48(u64 left, u64 right);

/* Advance the generator and return the upper 31 bits of the new state. */
s32 func_L00_0050CF78(void)
{
    u64 next = func_0012FE48(D_0049E688, 0x5851F42D4C957F2DUL) + 1;

    D_0049E688 = next;
    return (s32)((next >> 32) & 0x7FFFFFFFUL);
}
