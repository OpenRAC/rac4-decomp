#include "common.h"

extern void func_0049DF20(s32 player, s32 slot);
extern void func_0049DF70(s32 player, s32 slot);
void func_0049DFB8(s32 player, s32 count)
{
    s32 i = 0;
    for (; i < count; i++)
        func_0049DF20(player, i);
    for (; i < 2; i++)
        func_0049DF70(player, i);
}
