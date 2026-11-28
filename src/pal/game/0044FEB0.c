#include "common.h"

extern f32 func_00454158(f32);
extern f32 func_00454140(f32);

f32 func_0044FEB0(void *context, s32 mode, f32 phase)
{
    f32 result = 0.0f;

    if (phase < 0.0f || phase > 1.0f) {
        phase -= (f32)(s32)phase;
        if (phase < 0.0f)
            phase += 1.0f;
    }

    switch (mode) {
    case 1:
        result = phase;
        break;
    case 2:
        result = 1.0f - phase;
        break;
    case 3:
        result = func_00454158(((phase - 0.5f) * 2.0f) * 3.1415927f) * 0.5f + 0.5f;
        break;
    case 4:
        result = func_00454140(((phase - 0.5f) * 2.0f) * 3.1415927f) * 0.5f + 0.5f;
        break;
    case 5:
        result = 0.0f;
        if (phase < 0.5f) {
    case 0:
            result = 1.0f;
        }
        break;
    case 6:
        if (phase < 0.5f)
            result = phase * 2.0f;
        else
            result = (0.5f - (phase - 0.5f)) * 2.0f;
        break;
    case 7:
        if (phase > 0.5f)
            goto zero;
        if (phase < 0.25f)
            result = phase * 4.0f;
        else
            result = (0.25f - (phase - 0.25f)) * 4.0f;
        break;
    case 8:
        if (phase < 0.5f) {
zero:
            result = 0.0f;
            break;
        }
        if (phase < 0.75f)
            result = (phase - 0.5f) * 4.0f;
        else
            result = (0.25f - (phase - 0.75f)) * 4.0f;
        break;
    }

    return result;
}
