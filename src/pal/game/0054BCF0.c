#include "common.h"
s32 func_0054BCF0(const u8 *inventory, s32 slot, s32 kind)
{
    s32 count;
    s32 index;
    const u8 *position; u32 address;
    if (((u32)kind - 1U) >= 8U) return 0;
    address = (u32)inventory + 0xA44;
    position = (const u8 *)((u32)slot * 0x44U + address);
    count = 0;
    index = 9;
    do {
        if (*position == kind) ++count;
        position += 4;
    } while (--index >= 0);
    return count;
}
