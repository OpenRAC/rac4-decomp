#include "pal/points.h"

extern f32 func_00453940(f32 angle);
extern f32 func_00453928(f32 angle);

void func_0044B1B8(PalPoint2D *points, s32 count, f32 angle)
{
    f32 first = func_00453940(angle);
    s32 i = count - 1;
    f32 second = func_00453928(angle);

    for (; i >= 0; i--) {
        f32 x = points[i].x;
        f32 y = points[i].y;

        points[i].x = x * second + y * first;
        points[i].y = y * second - x * first;
    }
}
