/* cflags: -O2 -G8 -Wuninitialized -Wreturn-type */
#include "pal/object_bounds_query.h"

extern s32 D_00220530;

s32 func_L00_006A4E10(BoundsQueryObject *p, f32 *x, f32 *y, f32 *w, f32 *h)
{
    BoundsQueryRect input, output;
    if (p->v->supports(p, (u32)D_00220530)) {
        pal_bounds_query_init(&input);
        pal_bounds_query_init(&output);
        p->v->bounds(p, &input, &output, 1);
        *x = output.x;
        *y = output.y;
        *w = output.w;
        *h = output.h;
        return 1;
    }
    return 0;
}
