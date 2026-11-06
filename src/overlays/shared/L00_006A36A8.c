#include "common.h"
typedef struct Object Object;
typedef struct {
    f32 x, y, w, h, a, b;
} Rect;
typedef struct {
    char pad[0x14];
    s32 (*supports)(Object *, u32);
    char rest[0x10];
    void (*bounds)(Object *, Rect *, Rect *, s32);
} Vtable;
struct Object {
    s32 f0, f4;
    Vtable *v;
};
extern u32 D_00220484;
static inline void init(Rect *p)
{
    p->x = 0;
    p->y = 0;
    p->w = 1;
    p->h = 1;
    p->a = 0;
    p->b = 0;
}
s32 func_L00_006A36A8(Object *p, f32 *x, f32 *y, f32 *w, f32 *h)
{
    Rect input, output;
    if (p->v->supports(p, D_00220484)) {
        init(&input);
        init(&output);
        p->v->bounds(p, &input, &output, 1);
        *x = output.x;
        *y = output.y;
        *w = output.w;
        *h = output.h;
        return 1;
    }
    return 0;
}
