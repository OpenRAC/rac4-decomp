#ifndef PAL_OBJECT_BOUNDS_QUERY_H
#define PAL_OBJECT_BOUNDS_QUERY_H

#include "common.h"

typedef struct BoundsQueryObject BoundsQueryObject;
typedef struct {
    f32 x, y, w, h, a, b;
} BoundsQueryRect;
typedef struct {
    char pad[0x14];
    s32 (*supports)(BoundsQueryObject *, u32);
    char rest[0x10];
    void (*bounds)(BoundsQueryObject *, BoundsQueryRect *, BoundsQueryRect *, s32);
} BoundsQueryVtable;
struct BoundsQueryObject {
    s32 f0, f4;
    BoundsQueryVtable *v;
};

static inline void pal_bounds_query_init(BoundsQueryRect *p)
{
    p->x = 0;
    p->y = 0;
    p->w = 1;
    p->h = 1;
    p->a = 0;
    p->b = 0;
}

#endif
