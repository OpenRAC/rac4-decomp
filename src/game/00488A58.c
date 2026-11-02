#include "pal/object_parameter.h"

extern PalObjectParameter *func_004765F0(void *object);

f32 func_00488A58(void *object)
{
    PalObjectParameter *state = func_004765F0(object);
    f32 result = 1.0f;

    if (state != NULL && (state->flags & 0x20) != 0) {
        result = state->value;
    }
    return result;
}
