/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01EA9790(u32 *arg0, u32 arg1, u16 arg2)
{
    u32 r;

    if (arg0 == NULL || arg1 == 0) {
        return 0x64;
    }
    *arg0 = arg1;
    if (arg2 >= 2) {
        r = arg1 % arg2;
        if (r != 0) {
            *arg0 = arg1 + (arg2 - r);
        }
    }
    return 0;
}
