#include "pal/object_parameter.h"

extern PalObjectParameter *func_00476ED0(void *object);

f32 func_00489510(void *object)
{
    PalObjectParameter *state = func_00476ED0(object);
    f32 result = 1.0f;

    if (state != NULL && (state->flags & 0x20) != 0) {
        result = state->value;
    }
    return result;
}
