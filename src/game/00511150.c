#include "common.h"
extern u32 D_003367FC[], D_00336818[];
extern s32 D_003D37C0[];
extern u32 D_00222124;
extern u32 func_00511318(s32, u32, s32);
u32 func_00511150(s32 index, u32 id)
{
    u32 current = D_003367FC[index];
    u32 selected = D_00222124;
    if (id != ~0u)
        selected = id;
    if (current)
        return func_00511318(index, selected, (s32)(current - D_00336818[index]) / D_003D37C0[index]);
    else
        return ~0u;
}
