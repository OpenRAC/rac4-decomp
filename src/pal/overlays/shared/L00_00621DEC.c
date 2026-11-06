/* cflags: -O2 -G8 -Wa,-G0 -Wuninitialized */
#include "common.h"

extern f32 func_004760C0(f32 *value, f32 target, f32 fraction, f32 minimum);

/* Apply the shared adjustment to the value using fixed fraction and minimum. */
void func_L00_00621DEC(f32 *value, f32 target)
{
    func_004760C0(value, target, 0.200000003f, 0.00999999978f);
}
