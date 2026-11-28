/* cflags: -Wuninitialized */
#include "common.h"
#include "pal/scene_slot.h"

extern u8 D_00230380[];

s32 func_L01_00526630(s32 index)
{
    s32 result;
    SceneSlotState *state;

    if (((SceneSlotPlayer *)D_00230380)->actor->mode != 0x13)
        return 0;
    state = D_L01_00222A90[index].state;
    result = 0;
    if (state->f104 != 0 && state->f105 != 0)
        result = state->f106 == 0;
    return result;
}

s32 func_L01_00526688(s32 index)
{
    SceneSlotBinding *binding;

    if (((SceneSlotPlayer *)D_00230380)->actor->mode != 0x13)
        return 0;
    binding = &D_L01_00222A90[index].state->object->data->binding;
    if (func_L01_00526630(index) != 0 && binding->f14 >= 2)
        return 1;
    return 0;
}
