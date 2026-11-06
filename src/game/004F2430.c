#include "common.h"

extern s32 D_0021EDD4;
extern s32 D_0021EDD8;

s32 func_004F2430(u32 value)
{
    s32 result = 0;
    u32 adjusted = value - 1;
    if (!D_0021EDD4 && D_0021EDD8 == 1)
        adjusted = value - 21;
    switch (adjusted) {
    case 0:
    case 1:
    case 3:
    case 4:
        result = 0;
        break;
    case 5:
    case 7:
        result = 1;
        break;
    case 6:
    case 9:
        result = 2;
        break;
    case 10:
    case 12:
        result = 3;
        break;
    case 13:
    case 14:
        result = 4;
        break;
    }
    return result;
}
