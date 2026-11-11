/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

u32 func_01EA9BC8(void);

u32 func_01EBD758(u32 arg0)
{
    u32 r;

    do {
        r = func_01EA9BC8() % arg0;
    } while (r == 0);
    return r;
}
