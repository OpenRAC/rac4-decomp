#include "common.h"
void func_0014ADD8(const f32 *input, f32 *output, s32 degree, f32 scale)
{
    f32 factor = 1.0f;
    if (degree >= 0) {
        u32 remaining = (u32)degree + 1u;
        do {
            f32 value = *input++ * factor;
            factor *= scale;
            *output++ = value;
        } while (--remaining);
    }
}
