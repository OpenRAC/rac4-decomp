#include "common.h"
extern s32 D_0021EE48;
s32 func_004490A8(s32 index)
{
    s32 selector = D_0021EE48;
    if (index == 4)
        return 0;
    if (selector == 1)
        goto single;
    if (selector < 2)
        goto zero;
    if (selector != 2) {
        if (selector != 3)
            goto zero;
        switch (index) {
        case 3: return 9;
        case 2: return 8;
        case 1: return 7;
        case 0: return 6;
        default: break;
        }
    }
    if (index == 1)
        goto fourth;
    if (index < 2)
        goto third;
    if (index != 2)
        goto third;
    return 5;
fourth:
    return 4;
third:
    return 3;
single:
    if (index == 0)
        goto first;
    if (index == selector)
        return 2;
first:
    return 1;
zero:
    return 0;
}
