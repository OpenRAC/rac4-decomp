#include "common.h"

extern s32 D_0021F360;
/* Scale an input by five sixths and store the rounded result. */
void func_0047FE68(s32 value)
{
    D_0021F360 = (value * 5 + 2) / 6;
}
