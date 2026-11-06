#include "common.h"
typedef struct {
    f32 *values;
    u32 unknown4;
    s16 counter;
    u16 unknownA;
} DampingState;
void func_0014D870(DampingState *state)
{
    if (state->counter < 85) {
        s16 i;
        for (i = 0; i < 33; i++)
            state->values[i] *= 0.9919999837875366f;
    } else {
        state->counter = 84;
    }
    state->counter = (s16)((u32)(u16)state->counter + 1u);
}
