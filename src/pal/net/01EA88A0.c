#include "common.h"
s32 func_01EA88A0(s32 character)
{
    s32 below = character < 48;
    if (character < 58) {
        if (!below)
            return 1;
    }
    return 0;
}
