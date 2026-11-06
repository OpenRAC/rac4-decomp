/* cflags: -ffast-math */
#include "common.h"
typedef struct Control {
    u8 unknown0[0x120];
    f32 horizontal, vertical;
} Control;
typedef struct Axes {
    f32 first, vertical, horizontal;
} Axes;
extern f32 func_00476080(f32 *value, f32 target, f32 step);
void func_00514640(const Control *control, f32 *output, Axes *axes, f32 step)
{
    f32 target[2];
    f32 horizontal, vertical;
    target[0] = -control->horizontal;
    target[1] = -control->vertical;
    func_00476080(&axes->horizontal, target[0], step);
    horizontal = axes->horizontal;
    horizontal = horizontal > 1.0f ? 1.0f : horizontal;
    horizontal = horizontal < -1.0f ? -1.0f : horizontal;
    axes->horizontal = horizontal;
    output[0] = horizontal;
    func_00476080(&axes->vertical, target[1], step);
    vertical = axes->vertical;
    vertical = vertical > 1.0f ? 1.0f : vertical;
    vertical = vertical < -1.0f ? -1.0f : vertical;
    axes->vertical = vertical;
    output[1] = vertical;
}
