/* Reference: OpenRAC/rac3-decomp@cd0e7c20fd8a93116566ba2e024fa2f3536bd30c
 * src/frontbin/382380.c func_00386678.
 * Independently reconstructed from RAC4 PAL retail. */
#include "common.h"

extern u8 *func_00447A00(s32, s32, s32);
u8 *func_00447AD8(s32 x0, s32 y0, s32 z0, s32 x1, s32 y1, s32 z1, f32 factor)
{
    s32 x, y, z;
    u8 *result;
    if (factor < 0.5f) {
        if ((result = func_00447A00(x0, y0, z0)) == 0) {
            x = x1;
            y = y1;
            z = z1;
            goto fallback;
        }
    } else if ((result = func_00447A00(x1, y1, z1)) == 0) {
        x = x0;
        y = y0;
        z = z0;
    fallback:
        return func_00447A00(x, y, z);
    }
    return result;
}
