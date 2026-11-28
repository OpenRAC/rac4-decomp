#include "common.h"

static inline s32 stat_index(s32 index)
{
    switch (index) {
    case 0:
        return 17;
    case 1:
        return 24;
    case 2:
        return 11;
    case 3:
        return 31;
    case 4:
        return 38;
    default:
        return 17;
    }
}

s32 func_L00_0077FCD8(s32 index)
{
    return stat_index(index);
}

s32 func_L00_00780118(s32 index)
{
    return stat_index(index);
}
