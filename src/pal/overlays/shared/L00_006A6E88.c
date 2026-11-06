/* cflags: -O2 -G8 -Wuninitialized -Wreturn-type */
#include "pal/object_bounds_query.h"

extern u32 D_0022053C;

s32 func_L00_006A6E88(BoundsQueryObject *p, f32 *x, f32 *y, f32 *w, f32 *h)
{
    BoundsQueryRect input, output;
    if (p->v->supports(p, D_0022053C)) {
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
