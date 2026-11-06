#include "common.h"

s32 func_L00_00501E98(s32 kind)
{
    switch (kind) {
    case 1:
        return 0xCB;
    case 2:
        return 0xCA;
    case 4:
        return 0xC9;
    case 6:
        return 0xCC;
    default:
        return 0xFD;
    }
}
