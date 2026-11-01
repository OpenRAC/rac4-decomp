#include "common.h"

extern s32 D_00221680;
extern f32 func_004760C0(f32 *value, f32 target, f32 fraction, f32 minimum);

s32 func_0049B418(f32 *value, f32 target)
{
    if (D_00221680 != 0) {
        if (*value == target) {
            return 0;
        }
        *value = target;
        return 1;
    }
    return func_004760C0(value, target, 0.0f, 0.1f) != 0.0f;
}
