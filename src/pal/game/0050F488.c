#include "common.h"

void func_0050F488(void *object, u8 mask, s32 enable)
{
    u8 *flag = (u8 *)object + 0x54;
    if (enable) {
        *flag |= mask;
    } else {
        *flag &= ~mask;
    }
}
