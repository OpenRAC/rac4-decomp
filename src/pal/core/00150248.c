#include "common.h"

void func_00150248(void *state, f32 *out, s32 step, f32 input) {
    f32 phase;
    f32 turns;
    s32 rounded;

    phase = *(f32 *)state +
        (((input + *(f32 *)((s8 *)state + 8)) * 0.0061359233f) * (f32)step);
    turns = phase * 0.15915494f;
    if (turns > 0.0f) {
        f32 half = 0.5f;
        rounded = (s32)(turns + half);
    } else {
        f32 half = 0.5f;
        rounded = (s32)(turns - half);
    }
    phase -= (f32)rounded * 6.2831855f;
    *out = phase;
    *(f32 *)state = phase;
    *(f32 *)((s8 *)state + 8) = input;
}
