/* cflags: @ee29 -O2 -G0 */
#include "common.h"
s32 func_L02_004C75B0(void *actor)
{
    if (*(u8 *)((u8 *)actor + 103) == 11) {
        return *(u8 *)((u8 *)*(void **)((u8 *)actor + 172) + 514) != 0;
    }
    return 0;
}
