#include "common.h"
s32 func_004A8518(f32 angle, s32 count)
{
    if (angle < 0.001f && angle > -0.001f)
        angle = 0;
    if (angle < 0)
        angle += 360.0f;
    else if (angle >= 360.0f)
        angle -= 360.0f;
    angle /= (360.0f / count);
    return (s32)angle;
}
