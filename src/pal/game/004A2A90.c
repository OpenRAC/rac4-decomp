#include "common.h"

extern void func_0049FC68(s32);
s32 D_0021F6F8 = 1;

/* Select the active mode, resetting it when requested. */
void func_004A2A90(s32 active)
{
    if (active) {
        D_0021F6F8 = 4;
    } else {
        func_0049FC68(0);
        D_0021F6F8 = 1;
    }
}
