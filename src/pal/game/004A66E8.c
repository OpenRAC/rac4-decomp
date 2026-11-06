#include "common.h"

typedef struct {
    f32 targetX;
    f32 x;
    u8 unknown8[4];
    f32 targetY;
    f32 y;
    u8 unknown14[0xC];
    f32 target20;
    f32 current24;
    u8 visible;
    u8 unknown29[3];
    f32 alpha;
    u8 unknown30[8];
    s32 yTimer;
    s32 xTimer;
    u8 unknown40[4];
    s32 changed;
    u8 tail[8];
} State;

extern State D_00308068[];
extern s32 D_0021EE54;
extern s32 func_00506BB8(void);
extern f32 func_004760C0(f32 *, f32, f32, f32);
extern s32 func_00453CE8(s32 *);
extern void func_004A6888(void);

void func_004A66E8(void)
{
    s32 changed = 0;
    State *state = &D_00308068[func_00506BB8()];

    if (func_004760C0(&state->alpha, (f32)state->visible, 0.0f, 0.05f) != 0.0f) {
        changed = 1;
    }
    if (state->y != state->targetY) {
        if (state->visible) {
            state->y = state->targetY;
        } else if (state->yTimer) {
            func_00453CE8(&state->yTimer);
        } else {
            func_004760C0(&state->y, state->targetY, 0.1f, 0.3f);
        }
        changed = 1;
    } else {
        state->yTimer = 30;
    }
    if (state->x != state->targetX) {
        if (!state->visible) {
            state->x = state->targetX;
        } else if (state->xTimer) {
            func_00453CE8(&state->xTimer);
        } else {
            func_004760C0(&state->x, state->targetX, 0.1f, 0.3f);
        }
        changed = 1;
    } else {
        state->xTimer = 30;
    }
    if (D_0021EE54 != 1 && state->current24 != state->target20) {
        state->current24 = state->target20;
    }
    func_004A6888();
    state->changed = changed;
}
