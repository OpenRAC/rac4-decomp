#include "common.h"

s32 D_00221828 = 30135;

s32 func_L00_00769E40(s32 index)
{
    return *(s32 *)((u32)&D_00221828 + ((u32)index << 2));
}
