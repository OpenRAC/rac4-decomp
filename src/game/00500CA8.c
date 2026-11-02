#include "common.h"

typedef struct { f32 x, y; } Point;

void func_00500CA8(Point *out, Point *from, Point *to, f32 t)
{
    f32 remaining = 1.0f - t;
    out->x = remaining * from->x + t * to->x;
    out->y = remaining * from->y + t * to->y;
}
