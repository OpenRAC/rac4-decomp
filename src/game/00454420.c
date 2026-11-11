#include "common.h"

typedef struct {
    u32 first;
    u32 metrics;
} Glyph;
extern Glyph *D_0021DE8C;
extern s32 func_00454400(void);
s32 func_00454420(f32 *width, f32 *height, s32 mode)
{
    s32 result;
    *width = 0.0f;
    *height = 0.0f;
    result = 0;
    if (D_0021DE8C != 0) {
        if (mode != 0) {
            *width = (f32)((D_0021DE8C[0x41].metrics >> 17) & 0x3F);
            *height = (f32)((D_0021DE8C[0x41].metrics >> 9) & 0xFF) * 0.25f;
            result = 1;
        } else {
            s32 count = func_00454400();
            if (count > 0) {
                s32 i;
                u32 maximum = 0;
                for (i = 0; i < count; i++) {
                    u32 current = (D_0021DE8C[i].metrics >> 17) & 0x3F;
                    if (maximum < current) {
                        maximum = current;
                        *height = (f32)((D_0021DE8C[i].metrics >> 9) & 0xFF) * 0.25f;
                    }
                }
                *width = (f32)maximum;
                result = 1;
            }
        }
    }
    return result;
}
