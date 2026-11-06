#include "common.h"

extern void func_0049EF30(s32);
s32 D_0021F658 = 1;

/* Select the active mode, resetting it when requested. */
void func_004A1D58(s32 active)
{
    if (active) {
        D_0021F658 = 4;
    } else {
        func_0049EF30(0);
        D_0021F658 = 1;
    }
}
