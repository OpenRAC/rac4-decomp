#ifndef PAL_OBJECT_CALLBACK_RESOLVE_H
#define PAL_OBJECT_CALLBACK_RESOLVE_H

#include "common.h"

#include "pal/object_lookup_types.h"
extern u32 D_00220488;
static inline Object *resolve(s32 handle)
{
    Manager *m;
    Object *obj;
    void *world;
    if (D_00223248[0].context)
        m = D_00223248;
    else
        m = func_00502150();
    world = 0;
    if (m->context)
        world = *(void **)((u32)m->context + ((u32) * (s32 *)((char *)m->context + 0x14) << 2));
    obj = func_00501658(world, (u32)handle);
    if (obj && obj->vtable->isType(obj, D_00220488))
        return obj;
    return 0;
}

#endif
