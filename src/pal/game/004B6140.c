#include "pal/menu_state_00309940.h"

extern s32 D_00221858;
extern f32 func_00475FF0(f32 value, f32 lower, f32 upper);
extern f32 func_00475FB0(f32 first, f32 last, f32 fraction);
extern f32 func_004992B8(f32 value, f32 scale, f32 low, f32 high);
extern s32 func_00454480(s32 color, s32 target, f32 blend);
extern s32 func_004A2798(s32 *group, s32 id);
extern s32 func_005063C0(s32 handle, u32 value);

/* Blend item 5's colour while current is below 0.6, otherwise clear the accumulator. */
void func_004B6140(void) {
    PalMenuState00309940 *state;
    s32 color;
    f32 *slot;
    f32 spread;
    f32 step;
    f32 shaped;
    f32 span;

    state = &D_00309940[0];
    color = state->f10;
    slot = &state->accumulator;
    if (state->current < 0.6f) {
        spread = func_00475FF0(state->current, 0.0f, 0.6f);
        step = func_00475FB0(0.01f, 0.2f, 1.0f - spread);
        *slot += step;
        shaped = func_004992B8(*slot, 0.5f, 0.2f, 0.3f);
        span = func_00475FF0(state->current, 0.6f, 0.0f);
        color = func_00454480(color, func_00454480(color, 0x80FFFFFF, span), shaped);
    } else {
        *slot = 0.0f;
    }
    func_005063C0(func_004A2798(&D_00221858, 5), color);
}
