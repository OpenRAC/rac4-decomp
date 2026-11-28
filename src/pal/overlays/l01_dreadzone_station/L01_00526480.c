/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
#include "pal/scene_slot.h"

s32 func_L01_00526480(void *object)
{
    SceneSlotState *state = D_L01_00222A90[*(s16 *)((u8 *)object + 0x84)].state;

    if (state->f108 != 0) {
        state->f108 = 0;
        return 1;
    }
    return 0;
}
