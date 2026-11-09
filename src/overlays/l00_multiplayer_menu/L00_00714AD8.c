#include "common.h"

typedef struct NumericControl {
    u8 opaque[0x70];
    s32 value;
    s32 minimum;
    s32 maximum;
    s32 step;
} NumericControl;

extern s32 func_L00_007647B0(s32 identifier);

s32 func_L00_00714AD8(NumericControl *state, s32 action)
{
    s32 handled = 0;
    s32 changed = 0;
    s32 value;
    s32 proposed;

    if (action == 4 || action == 7) {
        state->value = (s32)((u32)state->value + (u32)state->step);
        handled = 1;
        changed = 1;
    } else if (action == 3) {
        state->value = (s32)((u32)state->value - (u32)state->step);
        handled = 1;
        changed = 1;
    }
    proposed = state->value;
    value = proposed > state->maximum ? state->maximum : proposed;
    value = value < state->minimum ? state->minimum : value;
    state->value = value;
    if (changed) {
        if (value != proposed) {
            func_L00_007647B0(4);
        } else {
            func_L00_007647B0(6);
        }
    }
    return handled;
}
