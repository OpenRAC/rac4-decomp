#include "common.h"

extern s32 func_L06_004C8A48(u8 *);
extern s32 D_00222694;

s32 func_L06_004C9BC0(void *arg0)
{
    u8 *state = *(u8 **)((u8 *)arg0 + 0xAC);
    if (*(s16 *)(state + 0x8C) != -1 && *(s16 *)(state + 0x8E) == 0)
        return 1;
    return func_L06_004C8A48((u8 *)(D_00222694 + (*(s32 *)(state + 0x6C) << 8))) != 0;
}