#ifndef PAL_OBJECT_TYPED_LOOKUP_H
#define PAL_OBJECT_TYPED_LOOKUP_H

#include "common.h"

#ifndef PAL_TYPED_LOOKUP_TYPE
#error PAL_TYPED_LOOKUP_TYPE must name the type identifier
#endif

#include "pal/object_lookup_types.h"
extern u32 PAL_TYPED_LOOKUP_TYPE;

static inline Manager *getManager(void)
{
    Manager *p = D_00223248;
    if (p->context)
        return p;
    return func_00502150();
}
static inline Object *valid(Object *p)
{
    if (p && p->vtable->isType(p, PAL_TYPED_LOOKUP_TYPE))
        return p;
    return 0;
}
static inline Object *getTyped(u32 id)
{
    Manager *m = getManager();
    char *state = m->context;
    void *table = 0;
    if (state)
        table = *(void **)(state + ((u32)*(s32 *)(state + 0x14) << 2));
    return valid(func_00501658(table, id));
}

#endif
