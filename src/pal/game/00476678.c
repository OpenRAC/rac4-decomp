/* Reference: OpenRAC/rac3-decomp@cd0e7c20fd8a93116566ba2e024fa2f3536bd30c
 * src/levels/shared/L01_004485E0.c func_L01_00448728.
 * Independently reconstructed from RAC4 PAL retail. */
#include "common.h"

extern f32 func_00476548(f32, f32, s32);
extern void func_00476020(f32 *, f32, f32, f32, f32);
extern f32 func_00454328(f32, f32);
f32 func_00476678(f32 *position, f32 *velocity, s32 mode, f32 target, f32 acceleration, f32 damping, f32 limit)
{
    f32 difference;
    if (mode == 2) {
        if ((target > 0.0f && *position < 0.0f) ||
            (target < 0.0f && *position > 0.0f)) {
            if (target < 0.0f)
                mode = -1;
            else
                mode = 1;
        } else
            mode = 0;
    }
    func_00476020(velocity, func_00476548(target, *position, mode),
                  acceleration, damping, limit);
    *position = func_00454328(*position, *velocity);
    difference = func_00476548(target, *position, mode);
    if (__builtin_fabsf(difference) < limit * 0.01f) {
        *position = target;
        *velocity = 0.0f;
        return *velocity;
    }
    return difference;
}
