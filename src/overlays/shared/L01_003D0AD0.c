#include "common.h"

s32 func_L01_003D0AD0(void *object) {
    s32 i;
    u8 *base = *(u8 **)(object + 0xAC);
    s32 *slots = (s32 *)(base + 0x50);
    u8 *flags = base + 0x8C;
    for (i = 0; i < 4; i++) {
        if (slots[i] != -1 && flags[i] == 0) return 0;
    }
    return 1;
}
