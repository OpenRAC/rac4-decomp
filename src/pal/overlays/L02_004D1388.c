#include "common.h"

extern s32 func_L01_004944F0(void *object);

/* Return a float status from the object predicate. */
f32 func_L02_004D1388(void *object)
{
    s32 active = func_L01_004944F0(object);
    f32 result = 1.0f;
    if (active == 0)
        result = 0.0f;
    return result;
}
