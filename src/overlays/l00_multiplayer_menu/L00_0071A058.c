#include "common.h"

extern s32 D_0021DF68;
extern void func_01EEF414(s32, s32);

void func_L00_0071A058(void)
{
    s32 channel = D_0021DF68;
    if (channel != 0)
        func_01EEF414(channel, 3);
}
