#include "common.h"
typedef struct Choice {
    u8 unknown0[8];
    u8 group;
} Choice;
extern Choice *func_0054B080(s32);

static inline u32 address(u32 base, u32 offset)
{
    return base + offset;
}

s32 func_0054B180(void *object, s32 choice)
{
    u8 *entry;
    s32 i;
    if (((u32)choice - 1U) >= 6)
        return 0;
    entry = (u8 *)address((u32)func_0054B080(choice)->group * 0x44, (u32)object + 0xA6C);
    for (i = 0; i < 2; i++, entry += 4) {
        if (*entry == choice)
            return 1;
    }
    return 0;
}
