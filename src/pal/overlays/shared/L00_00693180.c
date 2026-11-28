#include "common.h"

s32 D_L00_0022039C = 0;

s32 func_L00_00693180(void)
{
    switch (D_L00_0022039C) {
    case 1:
    case 2:
        return 1;
    case 3:
    case 4:
        return 2;
    case 5:
    case 11:
    case 16:
        return 3;
    default:
        return 0;
    }
}
