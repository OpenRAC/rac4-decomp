#include "common.h"
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern u8 D_00308108[];
extern s32 func_00505B20(void);
extern s32 func_00498A98(s32, s32);
extern s32 func_00498120(s32);

u32 func_004A89E8(s32 selection)
{
    s32 context = func_00505B20();
    u32 color = func_00498A98(context, selection);
    u32 current, other;
    u32 alpha;
    if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
        current = (u32)D_00308108 + (u32)context * 0xB8;
        other = (u32)D_00308108 + 0xB8;
        if (context)
            other = (u32)D_00308108;
        if (*(s32 *)(current + 0x24) == 0 &&
            (!*(s32 *)(other + 0x24) || selection != 2) &&
            selection != 14 && selection == func_00498120((u32)context < 1)) {
            alpha = color >> 24;
            color = ((u32)(s32)((f32)alpha * 0.2f) << 24) | (color & 0xFFFFFF);
        }
    }
    return color;
}
