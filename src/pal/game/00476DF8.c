/* Reference: OpenRAC/rac3-decomp@cd0e7c20fd8a93116566ba2e024fa2f3536bd30c
 * src/levels/shared/L01_00448CC0.c func_L01_00448D88.
 * Independently reconstructed from RAC4 PAL retail. */
#include "common.h"

extern void func_00476D98(s32 *, s32 *, s32 *, s32);
u32 func_00476DF8(u32 color, s32 permutation)
{
    s32 red, green, blue;
    u32 alpha;
    if (permutation == 0)
        return color;
    red = color & 0xFF;
    green = (s32)(color & 0xFF00) >> 8;
    blue = (color >> 16) & 0xFF;
    alpha = color >> 24;
    func_00476D98(&red, &green, &blue, permutation);
    return (alpha << 24) | ((u32)blue << 16) | ((u32)green << 8) | red;
}
