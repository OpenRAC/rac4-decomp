#include "common.h"

void func_L01_005A8680(u8 *object, const u8 *source)
{
    u16 *flags = (u16 *)(object + 0x36);
    if ((*(const u16 *)(source + 0x36) & 0x8000) == 0) {
        *flags &= 0x7FF;
        return;
    }
    *flags = (*flags | 0x8000) & 0x87FF;
    *flags |= *(const u16 *)(source + 0x36) & 0x7800;
}
