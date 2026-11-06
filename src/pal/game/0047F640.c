#include "common.h"

extern s32 D_0021DE40;
extern s32 func_00454480(s32, s32, f32);

s32 func_0047F640(s32 alpha)
{
    f32 value = (f32)(D_0021DE40 % 150) / 150.0f;
    s32 color;
    if (value < 0.333f) {
        color = func_00454480(0x00804020, 0x00208040, value * 3.0f);
    } else if (value < 0.667f) {
        color = func_00454480(0x00208040, 0x00402080, (value - 0.333f) * 3.0f);
    } else {
        color = func_00454480(0x00402080, 0x00804020, (value - 0.667f) * 3.0f);
    }
    color &= 0x00FFFFFF;
    return color | (alpha << 24);
}
