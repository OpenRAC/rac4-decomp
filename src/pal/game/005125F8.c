#include "common.h"

typedef struct Type1 {
    u32 f0;
    struct Type1 *f4, *f8;
} Type1;
extern u32 D_00220C28;
extern s32 D_00220C20;
extern Type1 *D_00339238[], *D_00339254[];
extern Type1 *func_00512470(u32);

/* Remove a live entry and move it to the free list, returning its next entry. */
Type1 *func_005125F8(u32 *handle)
{
    u32 index = (*handle & D_00220C28) >> D_00220C20;
    Type1 *p = func_00512470(*handle);
    Type1 *result = 0;
    if (p) {
        Type1 **free = &D_00339254[index];
        Type1 **live = (Type1 **)((u32)D_00339254 - 0x1C + index * 4);
        Type1 *previous = p->f8;
        Type1 *next = p->f4;
        if (previous)
            previous->f4 = next;
        if (p->f4)
            p->f4->f8 = p->f8;
        if (*live == p)
            *live = p->f4;
        p->f8 = 0;
        p->f4 = *free;
        p->f0 = 0xFFFFFFFFu;
        if (*free)
            (*free)->f8 = p;
        *free = p;
        result = next;
    }
    return result;
}
