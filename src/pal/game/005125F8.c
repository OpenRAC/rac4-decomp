#include "common.h"
#include "pal/handle_pool.h"

HandleEntry *func_005125F8(u32 *handle)
{
    u32 index = (*handle & D_00220C28) >> D_00220C20;
    HandleEntry *p = func_00512470(*handle);
    HandleEntry *result = 0;
    if (p) {
        HandleEntry **free = &D_00339238.free[index];
        HandleEntry **live = &D_00339238.live[index];
        HandleEntry *previous = p->previous;
        HandleEntry *next = p->next;
        if (previous)
            previous->next = next;
        if (p->next)
            p->next->previous = p->previous;
        if (*live == p)
            *live = p->next;
        p->previous = 0;
        p->next = *free;
        p->handle = 0xFFFFFFFFu;
        if (*free)
            (*free)->previous = p;
        *free = p;
        result = next;
    }
    return result;
}
