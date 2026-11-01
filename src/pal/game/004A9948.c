#include "common.h"

extern s32 func_00506BB8(void);
extern s32 D_0020C710[][3];

s32 func_004A9948(void)
{
    s32 index = func_00506BB8();
    s32 i;
    for (i = 0; i < 3; i++) {
        if (D_0020C710[index][i] == 0) {
            return i;
        }
    }
    return 3;
}
