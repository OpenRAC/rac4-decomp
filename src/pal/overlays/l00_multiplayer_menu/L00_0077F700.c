/* cflags: -Wuninitialized */
#include "common.h"
#include "pal/global_002234A4.h"

s32 func_L00_0077F700(void *arg0)
{
    u8 *base = D_002234A4;
    s32 result = *(s32 *)((u8 *)arg0 + 0x18);
    u8 *target = *(u8 **)(base + 0x64);
    if (*(s32 *)((u8 *)arg0 + 0x18)) {
        result = *(s32 *)(base + 0x14);
        *(s32 *)(base + 0x10) = 92;
        if (!result)
            *(s32 *)(base + 0x14) = 92;
    }
    target[0x174] = 0;
    return result;
}
