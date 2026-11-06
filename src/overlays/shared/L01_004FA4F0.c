/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern u8 D_003ABCE0[];

/* Returns the opaque table and its size for selector zero. */
void *func_L01_004FA4F0(s32 arg0, s32 arg1, u32 *arg2)
{
    if (arg1)
        return 0;
    *arg2 = 72;
    return D_003ABCE0;
}
