#include "common.h"

extern s32 D_0021DE3C;
extern f32 func_00454208(f32, f32);

f32 func_004A91A0(s32 arg0, s32 arg1)
{
    s32 object;
    f32 result;
    f32 distance;
    f32 x;
    f32 y;

    result = 360.0f;
    arg1 = *(s32 *)(arg0 + 0x2F00);
    distance = *(f32 *)(arg1 + 0x140) * *(f32 *)(arg1 + 0x140) +
               *(f32 *)(arg1 + 0x144) * *(f32 *)(arg1 + 0x144);
    if (D_0021DE3C == 4 || (*(s32 *)(arg1 + 0x1A0) & 0x10) != 0) {
        distance += *(f32 *)(arg1 + 0x148) * *(f32 *)(arg1 + 0x148) +
                    *(f32 *)(arg1 + 0x14C) * *(f32 *)(arg1 + 0x14C);
    }
    if (0.95f < distance) {
        object = *(s32 *)(arg0 + 0x2F00);
        x = *(f32 *)(object + 0x140);
        y = *(f32 *)(object + 0x144);
        if (D_0021DE3C == 4 || (*(s32 *)(object + 0x1A0) & 0x10) != 0) {
            x += *(f32 *)(object + 0x148);
            y += *(f32 *)(object + 0x14C);
        }
        result = func_00454208(x, y) * 180.0f / 3.1415927f;
    }
    return result;
}
