#include "common.h"

extern s32 D_00171C14_[];

s32 func_L01_004BDD78(void)
{
    s32 masked = D_00171C14_[0] & 0x04000000;
    return masked > 0;
}
