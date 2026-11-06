#include "common.h"
s32 func_L08_004CE858(const u8 *owner)
{
    s32 result = 0;
    switch (owner[0x20]) {
    case 2:
    case 4:
        result = 1;
        break;
    }
    return result;
}
