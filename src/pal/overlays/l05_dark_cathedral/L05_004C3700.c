/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

typedef struct {
    s32 index;
    u8 pad04[0xC];
    f32 progress;
    f32 initialZ;
    u8 direction;
    u8 pad19[7];
    s32 target;
    s32 delay;
    s32 timer;
    u8 active;
    u8 pending;
    u8 done;
} MoverState;

typedef struct {
    u8 pad00[0x18];
    f32 z;
    u8 pad1C[0x14];
    u8 marker;
    u8 pad31[0x7B];
    MoverState *state;
} Mover;

s32 func_L05_004C3700(Mover *mover, s32 target, s32 delay)
{
    MoverState *state = mover->state;

    if (state->target != 0)
        return 0;

    mover->marker = 0xFF;
    state->target = target;
    state->delay = delay;
    state->active = 1;
    state->pending = 0;
    state->direction = 0;
    state->timer = 0;
    state->done = 0;
    return 1;
}
