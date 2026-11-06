#include "common.h"

extern s32 D_002223C4;
extern s32 D_002225E8[2];
extern s32 D_002225F0[2];

extern f32 func_00454140(f32);
extern u32 func_00454480(u32, u32, f32);

// Blends colour b into a with func_00454480. Counter idx (0 or 1) of D_002225E8 goes up once per
// new value of D_002223C4 (reset clears it); frames is converted with (n * 5 + 2) / 6. Mode 0 is a
// triangle wave over 2n steps, mode 1 is func_00454140(pi * step / n) to the 4th power, any other mode is 0.5.
u32 func_L00_005E8CF8(u32 a, u32 b, s32 frames, s32 idx, s32 reset, s32 mode) {
    s32 *last = &D_002225F0[idx];
    s32 *count = &D_002225E8[idx];
    s32 n;
    s32 m;
    f32 t;

    if (*last != D_002223C4) {
        *last = D_002223C4;
        (*count)++;
    }
    if (reset) {
        *count = 0;
    }
    n = (frames * 5 + 2) / 6;
    switch (mode) {
    case 0:
        m = *count % (n * 2);
        if (m >= n) {
            t = 1.0f - (f32)(m - n) / (f32)n;
        } else {
            t = (f32)m / (f32)n;
        }
        break;
    case 1:
        t = func_00454140((f32)(*count % n) / (f32)n * 3.1415925f);
        t = t * t;
        t = t * t;
        break;
    default:
        t = 0.5f;
        break;
    }
    return func_00454480(b, a, t);
}
