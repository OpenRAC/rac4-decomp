#include "pal/object_parameter.h"

extern PalObjectParameter *func_004765F0(void *object);

s32 func_004889E0(void *object, s32 duration, f32 value)
{
    PalObjectParameter *state = func_004765F0(object);

    if (state == NULL) {
        return 0;
    }
    if ((state->flags & 0x20) != 0 && duration > 0) {
        state->dirty = 1;
        state->duration = duration;
        state->value = value;
    } else {
        state->duration = 0;
        state->value = 1.0f;
    }
    return 1;
}
