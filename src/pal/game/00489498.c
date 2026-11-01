#include "pal/object_parameter.h"

extern PalObjectParameter *func_00476ED0(void *object);

s32 func_00489498(void *object, s32 duration, f32 value)
{
    PalObjectParameter *state = func_00476ED0(object);

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
