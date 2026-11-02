#include "pal/points.h"

void func_0044B178(PalPoint2D *points, s32 count, f32 x, f32 y)
{
    s32 i;

    for (i = count - 1; i >= 0; i--) {
        points[i].x *= x;
        points[i].y *= y;
    }
}
