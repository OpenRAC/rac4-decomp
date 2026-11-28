#include "common.h"
#include "pal/handle_pool.h"

HandleEntry *func_00512528(u32 *handle, s32 activate)
{
    u32 pool = (*handle & D_00220C28) >> D_00220C20;
    HandleEntry **freeList = &D_00339238.free[pool];
    HandleEntry **liveList = &D_00339238.live[pool];
    HandleEntry *entry = *freeList;

    if (entry != NULL) {
        *freeList = entry->next;
        (*freeList)->previous = NULL;
        entry->previous = NULL;
        entry->next = *liveList;
        if (*liveList != NULL)
            (*liveList)->previous = entry;
        *liveList = entry;
        entry->handle = *handle;
        entry->methods->initialize(entry);
        if (activate != 0)
            entry->methods->activate(entry);
        return entry;
    }
    return NULL;
}
