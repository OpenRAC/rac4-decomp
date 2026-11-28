/* cflags: -Wuninitialized -mno-split-addresses */
#include "common.h"
#include "pal/l41_descriptor_state.h"

L41DescriptorObject *D_L41_00221A10 = NULL;

s64 func_L41_004469F8(void)
{
    s32 result;

    if (D_L41_00221A10 == NULL)
        return 0;
    result = 144;
    if (D_L41_00221A10->state->status80 < 0)
        return 0;
    return result;
}

s32 func_L41_00446900(void)
{
    if (D_L41_00221A10 == NULL)
        return 0;
    return D_L41_00221A10->state->value68;
}
extern u8 D_L41_002226A8[];
extern s32 func_004535C0(void *context, const f32 *position, f32 radius, f32 value);

s32 func_L41_00446748(void)
{
    L41DescriptorObject *object = D_L41_00221A10;
    L41DescriptorState *state;

    if (object == NULL)
        return 0;
    state = object->state;
    if (state->status80 < 0)
        return 0;

    return func_004535C0(D_L41_002226A8, object->position, 40.0f, state->value78) != -1;
}
