#include "common.h"

s32 func_L01_005917A0(const u8 *object)
{
    switch (*(const s16 *)(object + 0xBC)) {
    case 0x10E:
    case 0xE7D:
    case 0x1BC3:
    case 0x2692:
        return 1;
    default:
        return 0;
    }
}
