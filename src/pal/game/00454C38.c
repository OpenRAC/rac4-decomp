#include "common.h"

/* Reference: OpenRAC/OpenRAC@73f725bf54bb1bf6d8b9bb5b1511ed00d551fbde
 * OpenRAC/games/rac3/ntsc/src/frontbin/3896E8.c func_003899B8.
 * Independently reconstructed from RAC4 PAL retail. */

typedef struct {
    u32 first;
    u32 metrics;
} Glyph;
extern Glyph *D_0021DF14;
extern s32 func_00454C18(void);
s32 func_00454C38(f32 *width, f32 *height, s32 mode)
{
    s32 result;
    *width = 0.0f;
    *height = 0.0f;
    result = 0;
    if (D_0021DF14 != 0) {
        if (mode != 0) {
            *width = (f32)((D_0021DF14[0x41].metrics >> 17) & 0x3F);
            *height = (f32)((D_0021DF14[0x41].metrics >> 9) & 0xFF) * 0.25f;
            result = 1;
        } else {
            s32 count = func_00454C18();
            if (count > 0) {
                s32 i;
                u32 maximum = 0;
                for (i = 0; i < count; i++) {
                    u32 current = (D_0021DF14[i].metrics >> 17) & 0x3F;
                    if (maximum < current) {
                        maximum = current;
                        *height = (f32)((D_0021DF14[i].metrics >> 9) & 0xFF) * 0.25f;
                    }
                }
                *width = (f32)maximum;
                result = 1;
            }
        }
    }
    return result;
}
