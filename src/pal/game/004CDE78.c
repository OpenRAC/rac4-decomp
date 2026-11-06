#include "common.h"

extern s32 D_003D2778[];
/* Read an indexed value except for the two excluded entries. */
s32 func_004CDE78(s32 index)
{
    if (index == 8 || index == 9)
        return -1;
    return D_003D2778[index];
}
