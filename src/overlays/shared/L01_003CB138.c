/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern u8 D_003A0B98[];

/* Returns the opaque table and its size for selector sixteen. */
void *func_L01_003CB138(s32 arg0, s32 arg1, u32 *arg2)
{
    if (arg1 != 16)
        return 0;
    *arg2 = 28;
    return D_003A0B98;
}
