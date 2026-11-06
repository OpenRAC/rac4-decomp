#include "common.h"

/* Scalar angular interpolation, with reference to OpenRAC/rac2-decomp
 * src/levels/shared/L00_00316F60.c, func_L00_0031ABE0,
 * commit 99f35ac2c084fc59cdf3d631f8f960a825e7a49c, GPL-3.0.
 * RAC4 operation grouping and targets follow retail, including the original VU call. */
extern f32 func_00454140(f32 angle);
extern f32 func_00454328(f32 angle, f32 delta);
extern f32 func_00454370(f32 to, f32 from);

f32 func_L01_00596140(f32 from, f32 to, f32 phase)
{
    f32 difference = func_00454370(to, from);
    f32 weight = (1.0f - func_00454140(phase * 3.1415927f)) * 0.5f;

    return func_00454328(from, difference * weight);
}
