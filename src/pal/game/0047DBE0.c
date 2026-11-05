#include "common.h"

extern s32 func_0047DBB0(s32 index);

s32 func_0047DBE0(s32 mode)
{
    switch (mode) {
    case 0:
        return 0;
    case 1:
    case 2:
    case 3:
    case 7:
    case 8:
    case 9:
    case 10:
        return 1;
    case 4:
        return func_0047DBB0(6);
    case 5:
        return func_0047DBB0(7);
    case 6:
        return func_0047DBB0(9);
    case 11:
        return func_0047DBB0(8);
    case 12:
        return func_0047DBB0(4) || func_0047DBB0(5);
    case 13:
        return 0;
    }
    return 0;
}
