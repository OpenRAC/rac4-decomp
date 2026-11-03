#include "common.h"
extern s32 func_00509248(u32, s32), func_005063C0(u32, u32);
extern s32 func_00506978(u32, f32, f32), func_005052D0(u32, f32, f32), func_00505D18(u32, f32);
static inline s32 combine(s32 a, s32 b)
{
    return a & b;
}
s32 func_00507828(u32 id, s32 option, u32 color, f32 x, f32 y, f32 width, f32 height, f32 amount)
{
    s32 first = func_00509248(id, option);
    s32 result = func_005063C0(id, color) != 0;
    if (!first)
        result = 0;
    result = combine(result, func_00506978(id, width, height) != 0);
    result = combine(result, func_005052D0(id, x, y) != 0);
    result = combine(result, func_00505D18(id, amount) != 0);
    return result;
}
