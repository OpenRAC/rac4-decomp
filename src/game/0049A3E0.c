#include "common.h"

typedef struct { u8 pad00[0x1C4]; u32 flags; u8 pad1C8[0x389]; u8 mode; } State;
typedef struct { u8 pad00[0x2F00]; State *state; } Object;
extern Object *func_00510BE8(s32 index);
extern s32 D_0021EDD4;

s32 func_0049A3E0(s32 index)
{
    State *state = func_00510BE8(index)->state;
    s32 result = 0;
    if ((state->flags & 0x800) != 0 || (D_0021EDD4 != 1 && state->mode == 1)) {
        result = 1;
    }
    return result;
}
