#include "common.h"

typedef struct { u8 pad00[0x1C4]; u32 flags; u8 pad1C8[0x389]; u8 mode; } State;
typedef struct { u8 pad00[0x2F00]; State *state; } Object;
extern Object *func_00511CC0(s32 index);
extern s32 D_0021EE54;

s32 func_0049B118(s32 index)
{
    State *state = func_00511CC0(index)->state;
    s32 result = 0;
    if ((state->flags & 0x800) != 0 || (D_0021EE54 != 1 && state->mode == 1)) {
        result = 1;
    }
    return result;
}
