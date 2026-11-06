#include "common.h"

/* Advance a value and wrap it by one at either signed unit boundary. */
void func_00433638(f32 *p, f32 x)
{
    f32 result = *p + x;
    *p = result;
    if (result >= 1.0f)
        *p = result - 1.0f;
    else if (result <= -1.0f)
        *p = result + 1.0f;
}
