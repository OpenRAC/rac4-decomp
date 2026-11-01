#include "common.h"

void func_0050DEB8(void *object, u32 mask, s32 enable)
{
    u8 *flag = (u8 *)object + 0x1EC;
    if (enable) {
        *flag |= mask;
    } else {
        *flag &= ~mask;
    }
}
