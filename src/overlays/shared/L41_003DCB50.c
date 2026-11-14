#include "common.h"

extern u8 D_003980C8[];

// Set state index on object's sub-struct and copy table entry.
void func_L41_003DCB50(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0xAC);

    if (*(s32 *)(p + 0x54) != arg1) {
        *(s32 *)(p + 0x54) = arg1;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x64) = *(s32 *)(D_003980C8 + (arg1 << 3));
        *(s32 *)(p + 0x68) = *(s32 *)(D_003980C8 + (arg1 << 3) + 4);
        *(u16 *)(arg0 + 0x36) = (*(u16 *)(arg0 + 0x36) & 0x87FF) | (arg1 << 11);
    }
}
