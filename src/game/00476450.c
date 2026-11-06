/* Reference: OpenRAC/rac3-decomp@cd0e7c20fd8a93116566ba2e024fa2f3536bd30c
 * src/levels/shared/L01_00448CC0.c func_L01_00448CC0.
 * Independently reconstructed from RAC4 PAL retail. */
#include "common.h"

u32 func_00476450(f32 red, f32 green, f32 blue, f32 alpha)
{
    u32 g = ((s32)(green * 255.0f) & 0xFF) << 8;
    return ((s32)(red * 255.0f) & 0xFF) | g |
           (((s32)(blue * 255.0f) & 0xFF) << 16) |
           ((u32)(s32)(alpha * 255.0f) << 24);
}
