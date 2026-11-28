#include "common.h"

typedef struct {
    u8 pad000[0x600];
    s32 slot;
    u8 pad604[0x14];
    u8 mode;
} LocalState;

typedef struct {
    u8 pad00[0xAC];
    LocalState *state;
} LocalEntity;

s64 func_L01_0045D318(const LocalEntity *entity)
{
    const LocalState *state = entity->state;
    s64 result;
    s32 active;

    result = 0;
    if (state->mode == 1) {
        active = state->slot != -1;
        result = active;
    }
    return result;
}
