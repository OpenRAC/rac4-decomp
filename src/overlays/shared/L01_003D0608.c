#include "common.h"

typedef struct { u16 f0; u16 f2; u32 f4; u32 f8; } T;
extern T D_001F1400[];

s32 func_L01_003D0608(void *object) {
    s32 i;
    s32 *slots = (s32 *)(*(u8 **)(object + 0xAC) + 0x50);
    for (i = 0; i < 4; i++) {
        if (slots[i] != -1 && D_001F1400[slots[i]].f0 == 0) return 0;
    }
    return 1;
}
