/* cflags: -mno-split-addresses */
#include "common.h"

typedef struct {
    u32 first;
    u32 metrics;
} Glyph;
extern Glyph *D_0021DF14[];
extern s32 func_00454A70(const u8 *, s32, s32 *);
s32 func_00454600(const u8 *text, s32 length, f32 scale)
{
    s32 offset = 0;
    s32 running = 1;
    f32 maximum = 0.0f;
    s32 glyph = 0;
    for (; running && offset != length; offset++) {
        if (text[offset] == 0) {
            running = 0;
        } else {
            f32 width, height, value;
            offset += func_00454A70(text, offset, &glyph);
            width = (f32)((D_0021DF14[0][glyph].metrics >> 17) & 0x3F) * scale;
            height = (f32)((D_0021DF14[0][glyph].metrics >> 9) & 0xFF) * scale;
            value = width + height * 0.25f;
            if (maximum < value)
                maximum = value;
        }
    }
    return (s32)maximum;
}
