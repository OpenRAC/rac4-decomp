#include "common.h"
void func_L00_00749408(u8 *owner, const u32 *input, s32 count)
{
    s32 index;
    if (count > 256)
        count = 256;
    *(s32 *)(owner + 0x668) = 0;
    *(s32 *)(owner + 0x660) = count;
    *(s32 *)(owner + 0x664) = 0;
    for (index = 0; index < *(s32 *)(owner + 0x660); index++) {
        *(u32 *)(owner + 0x260 + index * 4) = *input++;
    }
}
