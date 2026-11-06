#include "common.h"

extern s32 D_0020C710[][3];

s32 func_004A99A0(s32 index)
{
    s32 i;
    for (i = 0; i < 3; i++) {
        if (D_0020C710[index][i] == 0) {
            return i;
        }
    }
    return 3;
}
