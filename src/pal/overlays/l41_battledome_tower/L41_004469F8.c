/* cflags: -Wuninitialized */
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