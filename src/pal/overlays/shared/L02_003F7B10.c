#include "common.h"

typedef struct {
    u8 pad0[0x614];
    u8 flag614;
    u8 flag615;
    u8 pad616;
    u8 flag617;
    u8 mode;
} DispatchState;

typedef struct {
    u8 pad0[0xAC];
    DispatchState *state;
} DispatchObject;

s32 func_L02_003F7B10(DispatchObject *object, s32 selector)
{
    DispatchState *state = object->state;

    switch (selector) {
    case 0:
        return state->mode == 0;
    case 2:
        return state->mode == 1;
    case 1:
        return state->flag615 != 0;
    case 3:
        return state->mode == 2;
    case 4:
        return state->flag614 == 0;
    case 5:
        return state->flag617 != 0;
    default:
        return 0;
    }
}
