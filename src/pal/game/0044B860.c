#include "pal/points.h"

extern f32 func_00454158(f32 angle);
extern f32 func_00454140(f32 angle);

void func_0044B860(PalPoint2D *points, s32 count, f32 angle)
{
    f32 first = func_00454158(angle);
    s32 i = count - 1;
    f32 second = func_00454140(angle);

    for (; i >= 0; i--) {
        f32 x = points[i].x;
        f32 y = points[i].y;

        points[i].x = x * second + y * first;
        points[i].y = y * second - x * first;
    }
}
