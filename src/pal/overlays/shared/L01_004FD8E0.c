#include "common.h"

void func_L01_004FD8E0(u8 *object, s64 enabled)
{
    s32 i;
    u8 *state = *(u8 **)(object + 0xAC);
    if (enabled) {
        u8 *child;
        u8 **slots;
        *(u32 *)(object + 0x98) = *(u32 *)(*(u8 **)(object + 0x24) + 0x10);
        child = *(u8 **)(state + 0x228);
        if (child) {
            *(u32 *)(child + 0x98) = *(u32 *)(*(u8 **)(child + 0x24) + 0x10);
            slots = (u8 **)(*(u8 **)(*(u8 **)(state + 0x228) + 0xAC) + 0xD0);
            for (i = 3; i >= 0; i--, slots++) {
                u8 *part = *slots;
                if (part)
                    *(u32 *)(part + 0x98) = *(u32 *)(*(u8 **)(part + 0x24) + 0x10);
            }
        }
    } else {
        u8 *child;
        u8 **slots;
        *(u32 *)(object + 0x98) = 0;
        child = *(u8 **)(state + 0x228);
        if (child) {
            *(u32 *)(child + 0x98) = 0;
            slots = (u8 **)(*(u8 **)(*(u8 **)(state + 0x228) + 0xAC) + 0xD0);
            for (i = 3; i >= 0; i--, slots++) {
                u8 *part = *slots;
                if (part)
                    *(u32 *)(part + 0x98) = 0;
            }
        }
    }
}
