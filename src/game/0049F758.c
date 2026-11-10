#include "common.h"

typedef struct {
    u8 prefix[0x14];
    f32 x, y, width, factor;
    u8 gap[0xC];
    s32 frame;
    u8 gap34[0x10];
    u8 active;
    u8 tail[0x1BB];
} State;
extern State D_00307254[];
void func_0049F758(s32 index, f32 *x, f32 *y, f32 *width, f32 *height)
{
    f32 intermediate, spacing;
    State *state = &D_00307254[index];
    if (state->active)
        spacing = state->width * 0.48582998f;
    else
        spacing = 0.024038462f;
    intermediate = state->factor * (f32)state->frame;
    *height = intermediate;
    *height = intermediate + (f32)(state->frame + 1) * 0.0072115385f +
              (spacing + 0.024038462f) + 0.009615385f;
    *x = state->x;
    *y = state->y;
    *width = state->width + 0.0078125f;
}
