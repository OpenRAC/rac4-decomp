#include "common.h"

s32 func_004C0F78(u32 value)
{
    s32 result = 0;
    switch (value) {
    case 2:
        result = 3;
        break;
    case 0:
    case 1:
    case 3:
    case 4:
        result = 2;
        break;
    }
    return result;
}
