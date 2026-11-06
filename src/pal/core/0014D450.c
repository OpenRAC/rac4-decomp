/* cflags: -fno-opt-stack */
#include "common.h"
typedef struct Detector Detector;
typedef struct DampingState DampingState;
typedef struct {
    u32 unknown0;
    Detector *detector;
    DampingState *damping;
    f32 pitch, strength;
    s16 result, target;
    u16 mode, period;
    s16 active;
    u8 updateEnabled;
} State;
extern f32 func_0014D868(const DampingState *state);
extern f32 func_0014D1D8(f32 value);
extern s32 func_0014D9E0(Detector *state, f32 value);
extern void func_0014DA78(s16 mode, Detector *state, f32 threshold, f32 level);
extern void func_0014DB18(Detector *state, f32 value);
extern s32 func_0014DDC0(s16 mode, u16 period, Detector *state, f32 threshold);
extern s32 func_0014DE80(const Detector *state, s32 mode, f32 strength);
extern void func_0014D738(u8 index, DampingState *state);
extern s32 func_0014D5A0(DampingState *state, s16 target);
extern void func_0014D870(DampingState *state);
s32 func_0014D450(State *state, f32 pitch, f32 strength)
{
    f32 level;
    f32 threshold;
    u8 index;
    s32 positive;
    state->pitch = pitch;
    state->strength = strength;
    level = func_0014D868(state->damping);
    positive = state->target >= 0;
    if (!state->mode)
        state->mode = 1;
    if (!state->period)
        state->period = 90;
    threshold = func_0014D1D8(pitch);
    index = (u8)(s32)(threshold + 0.5f);
    func_0014D9E0(state->detector, pitch);
    func_0014DA78((s16)state->mode, state->detector, threshold, level);
    func_0014DB18(state->detector, pitch);
    state->active = func_0014DDC0((s16)state->mode, state->period, state->detector, threshold);
    if (func_0014DE80(state->detector, positive, strength)) {
        func_0014D738(index, state->damping);
        if (state->updateEnabled)
            state->result = func_0014D5A0(state->damping, state->target);
    } else {
        func_0014D870(state->damping);
    }
    return 0;
}
