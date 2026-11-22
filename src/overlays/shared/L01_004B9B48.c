#include "common.h"
u32 func_L01_004B9B48(s32 a, u32 flag) {
    u32 c = (flag & 1) ? 0x40204080 : 0x40808080;
    f32 k = 1.0f - (f32)a * 0.125f;
    return ((u32)(s32)((f32)(c >> 24) * k) << 24) | (c & 0xFFFFFF);
}
