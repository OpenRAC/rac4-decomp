#include "common.h"
#include "pal/scene_slot.h"

/* PAL: from rac3-decomp's func_L01_003EC9E0, constants adapted */
void func_L01_00526848(s32 index)
{
    SceneSlotState *state = D_L01_00222A90[index].state;

    state->fB3 = 1;
    state->fB4 = 0;
}
