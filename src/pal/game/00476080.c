/* cflags: -ffast-math -fno-delayed-branch */
#include "common.h"

f32 func_00476080(f32 *current, f32 target, f32 step)
{
    f32 value = *current;
    f32 negative = -step;
    f32 delta = target - value;
    delta = delta > step ? step : delta;
    delta = delta < negative ? negative : delta;
    value += delta;
    *current = value;
    return __builtin_fabsf(target - value);
}
