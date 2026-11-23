#include "common.h"

extern s32 func_0047D4E8(void);

f32 func_L01_005A9260(s32 selector)
{
    u8 *context;
    f32 tier;

    context = (u8 *)func_0047D4E8();
    if (((u8 *)((u32)context + (u32)selector))[0x1F4] == 0)
        return 0.0f;

    tier = 1.0f;
    if (context[0x204] != 0)
        tier = 8.0f;
    else if (context[0x203] != 0)
        tier = 7.0f;
    else if (context[0x202] != 0)
        tier = 6.0f;
    else if (context[0x201] != 0)
        tier = 5.0f;
    else if (context[0x200] != 0)
        tier = 4.0f;
    else if (context[0x1FF] != 0)
        tier = 3.0f;
    else if (context[0x1FE] != 0)
        tier = 2.0f;

    if (selector == 1)
        return tier;
    if (selector == 3)
        return tier * 3.0f;
    if (selector == 2)
        return tier * 5.0f;
    if (selector == 4)
        return tier * 5.0f;
    if (selector == 5)
        return tier * 10.0f;
    return 0.0f;
}
