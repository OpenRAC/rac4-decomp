/* cflags: -ffast-math */
#include "common.h"

extern f32 func_00454370(f32 to, f32 from);
extern f32 func_00454328(f32 angle, f32 delta);

f32 func_L01_003F6408(f32 current, f32 target, f32 step)
{
    f32 difference = func_00454370(target, current);
    f32 amount;
    f32 limit;

    if (difference > 0.0f)
        amount = step;
    else
        amount = -step;
    limit = __builtin_fabsf(difference);
    amount = amount > limit ? limit : amount;
    amount = amount < -limit ? -limit : amount;
    return func_00454328(current, amount);
}
