#include "common.h"

extern f32 func_00454158(f32);
extern f32 func_00454328(f32, f32);
extern u32 func_00454480(u32, u32, f32);

// Advances the counter up to 20 and the angle by speed degrees per frame (1/50 s), then returns
// a colour from func_00454480 whose alpha grows with the counter and whose blend follows the sine
// of the angle; with flag set it returns 0x600000FF instead.
u32 func_L01_00640588(f32 *angle, s32 *count, s32 flag, f32 speed) {
    s32 n = *count + 1;
    u32 alpha;
    u32 color;

    *count = n < 21 ? n : 20;
    *angle = func_00454328(*angle, speed * 0.017453292f * 0.020000001f);
    alpha = (*count * 5) << 24;
    color = func_00454480(alpha | 0xFF0F, alpha | 0xFFFFFF, func_00454158(*angle) * 0.5f + 0.5f);
    if (flag) {
        color = 0x600000FF;
    }
    return color;
}
