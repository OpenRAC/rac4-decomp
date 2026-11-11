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
void func_0049F828(s32 index, s32 row, f32 *x, f32 *y, f32 *width, f32 *height)
{
    State *state = &D_00307254[index];
    f32 spacing;
    f32 value;

    f32 a, b, c;
    s32 frame;
    if (state->active)
        spacing = state->width * 0.48582998f;
    else
        spacing = 0.024038462f;
    frame = state->frame;
    a = state->factor * (f32)frame;
    b = (f32)(frame + 1) * 0.0072115385f;
    c = spacing + 0.024038462f;
    *width = state->width;
    *height = state->factor;
    *x = state->x;
    value = (state->y - ((a + b + c) * 0.5f)) + (spacing + 0.0072115385f);
    *y = value;
    value = value + *height * 0.5f;
    *y = value;
    *y = value + (*height + 0.0072115385f) * (f32)row;
}
