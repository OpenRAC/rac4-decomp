#include "common.h"

extern s32 func_00505B20(void);
extern s32 D_0020C690[][3];

s32 func_004A8BD0(void)
{
    s32 index = func_00505B20();
    s32 i;
    for (i = 0; i < 3; i++) {
        if (D_0020C690[index][i] == 0) {
            return i;
        }
    }
    return 3;
}
