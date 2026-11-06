#include "common.h"
extern s32 D_0021EE54;
extern s32 D_0021EE58;
extern u8 D_00308208[];
extern s32 func_00506BB8(void);
extern s32 func_004997D0(s32, s32);
extern s32 func_00498E58(s32);

u32 func_004A9760(s32 selection)
{
    s32 context = func_00506BB8();
    u32 color = func_004997D0(context, selection);
    u32 current, other;
    u32 alpha;
    if (D_0021EE54 == 0 && D_0021EE58 == 1) {
        current = (u32)D_00308208 + (u32)context * 0xB8;
        other = (u32)D_00308208 + 0xB8;
        if (context)
            other = (u32)D_00308208;
        if (*(s32 *)(current + 0x24) == 0 &&
            (!*(s32 *)(other + 0x24) || selection != 2) &&
            selection != 14 && selection == func_00498E58((u32)context < 1)) {
            alpha = color >> 24;
            color = ((u32)(s32)((f32)alpha * 0.2f) << 24) | (color & 0xFFFFFF);
        }
    }
    return color;
}
