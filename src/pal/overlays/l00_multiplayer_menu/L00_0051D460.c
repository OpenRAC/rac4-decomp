#include "common.h"

s32 func_L00_0051D460(s32 kind)
{
    switch (kind) {
    case 6:
    case 0x13:
        return 6;
    case 0x42:
    case 0x43:
    case 0x46:
    case 0x71:
    case 0x74:
        return 0x74;
    case 0x1C:
        return 0x1C;
    default:
        return 0;
    }
}
