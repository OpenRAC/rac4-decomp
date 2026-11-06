#include "common.h"
extern s32 func_005081B0(u32, s32), func_00505328(u32, u32);
extern s32 func_005058E0(u32, f32, f32), func_00504238(u32, f32, f32), func_00504C80(u32, f32);
static inline s32 combine(s32 a, s32 b)
{
    return a & b;
}
s32 func_00506790(u32 id, s32 option, u32 color, f32 x, f32 y, f32 width, f32 height, f32 amount)
{
    s32 first = func_005081B0(id, option);
    s32 result = func_00505328(id, color) != 0;
    if (!first)
        result = 0;
    result = combine(result, func_005058E0(id, width, height) != 0);
    result = combine(result, func_00504238(id, x, y) != 0);
    result = combine(result, func_00504C80(id, amount) != 0);
    return result;
}
