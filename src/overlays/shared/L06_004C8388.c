#include "common.h"

extern s32 func_L06_004C7210(u8 *);
extern s32 D_00222614;

s32 func_L06_004C8388(void *arg0)
{
    u8 *state = *(u8 **)((u8 *)arg0 + 0xAC);
    if (*(s16 *)(state + 0x8C) != -1 && *(s16 *)(state + 0x8E) == 0)
        return 1;
    return func_L06_004C7210((u8 *)(D_00222614 + (*(s32 *)(state + 0x6C) << 8))) != 0;
}
