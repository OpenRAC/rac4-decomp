#include "common.h"

// Append a 0x24-byte entry: return its index and link it into the list.
void func_L00_00775680(u8 *arg0, u8 *arg1) {
    u32 base = (u32)arg0 + 0x10;
    u32 index = ((u32)arg1 - base) / 0x24;

    *(s32 *)(arg1 + 0x0) = 2;
    *(s32 *)(arg1 + 0x20) = *(s32 *)(arg0 + 0xC);
    *(s32 *)(arg0 + 0xC) = index;
}
