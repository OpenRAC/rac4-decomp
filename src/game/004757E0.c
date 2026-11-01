#include "common.h"

extern f32 fabsf(f32 value);

f32 func_004757E0(f32 *value, f32 target, f32 fraction, f32 minimum)
{
    f32 old = *value;
    f32 delta = target - old;

    if (fraction >= 1.0f || fabsf(delta) < minimum) {
        *value = target;
    } else {
        delta *= fraction;
        if (fabsf(delta) < minimum) {
            delta = minimum;
            if (!(old < target)) {
                delta = -delta;
            }
        }
        *value += delta;
    }
    return delta;
}
