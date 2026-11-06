#include "common.h"

/* Three-component angular interpolation, adapted from OpenRAC/rac2-decomp
 * src/levels/shared/L00_00316F60.c, func_L00_0031AD40,
 * commit 99f35ac2c084fc59cdf3d631f8f960a825e7a49c, GPL-3.0.
 * RAC4 targets, float constant, component order and ABI checked against retail. */
extern f32 func_00453928(f32 angle);
extern f32 func_00453B10(f32 angle, f32 delta);
extern f32 func_00453B58(f32 to, f32 from);

void func_L01_00591F88(f32 *output, const f32 *from, const f32 *to, f32 phase)
{
    f32 weight = (1.0f - func_00453928(phase * 3.1415927f)) * 0.5f;

    output[0] = func_00453B10(from[0], func_00453B58(to[0], from[0]) * weight);
    output[1] = func_00453B10(from[1], func_00453B58(to[1], from[1]) * weight);
    output[2] = func_00453B10(from[2], func_00453B58(to[2], from[2]) * weight);
}
