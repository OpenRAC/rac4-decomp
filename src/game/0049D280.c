#include "common.h"

extern void func_0049D1E8(s32 player, s32 slot);
extern void func_0049D238(s32 player, s32 slot);
void func_0049D280(s32 player, s32 count)
{
    s32 i = 0;
    for (; i < count; i++)
        func_0049D1E8(player, i);
    for (; i < 2; i++)
        func_0049D238(player, i);
}
