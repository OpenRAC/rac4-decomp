#include "common.h"

extern s32 func_0047D278(s32 index);

s32 func_0047D2A8(s32 mode)
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
        return func_0047D278(6);
    case 5:
        return func_0047D278(7);
    case 6:
        return func_0047D278(9);
    case 11:
        return func_0047D278(8);
    case 12:
        return func_0047D278(4) || func_0047D278(5);
    case 13:
        return 0;
    }
    return 0;
}
