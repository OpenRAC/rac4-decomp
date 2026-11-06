#include "common.h"

extern u8 D_0020BA40[];

void func_0043A0F8(u32 value, s32 index)
{
    if (*(u32 *)D_0020BA40 & 1)
        *(u16 *)((u32)D_0020BA40 + ((u32)index << 1) + 4) = value;
}
