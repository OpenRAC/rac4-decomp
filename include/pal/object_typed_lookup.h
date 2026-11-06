#ifndef PAL_OBJECT_TYPED_LOOKUP_H
#define PAL_OBJECT_TYPED_LOOKUP_H

#include "common.h"

#include "pal/object_lookup_types.h"

static inline Manager *getManager(void)
{
    Manager *p = D_00223248;
    if (p->context)
        return p;
    return func_00502150();
}
/* TYPE is the address of the global holding the type identifier, read at the check. */
static inline Object *valid(Object *p, const u32 *type)
{
    if (p && p->vtable->isType(p, *type))
        return p;
    return 0;
}
static inline Object *getTyped(u32 id, const u32 *type)
{
    Manager *m = getManager();
    char *state = m->context;
    void *table = 0;
    if (state)
        table = *(void **)(state + ((u32)*(s32 *)(state + 0x14) << 2));
    return valid(func_00501658(table, id), type);
}

#endif
