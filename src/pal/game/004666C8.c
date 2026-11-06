#include "common.h"
extern u32 D_0021DB64;

u32 func_004666C8(s32 kind)
{
    u32 result = 0;
    switch (kind) {
    case 1:
        result = D_0021DB64 & 0x2;
        break;
    case 3:
        result = D_0021DB64 & 0x4;
        break;
    case 4:
        result = D_0021DB64 & 0x10;
        break;
    case 6:
        result = D_0021DB64 & 0x800;
        break;
    case 5:
        result = D_0021DB64 & 0x8;
        break;
    case 7:
        result = D_0021DB64 & 0x200;
        break;
    }
    return result;
}
