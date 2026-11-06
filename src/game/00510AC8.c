/* Reference: OpenRAC/rac3-decomp@cd0e7c20fd8a93116566ba2e024fa2f3536bd30c
 * src/frontbin/3F2238.c func_003F2268.
 * Independently reconstructed from RAC4 PAL retail. */
#include "common.h"

typedef struct {
    void *type;
    u8 *base;
    u32 capacity;
    s32 stride;
    u32 used;
    s32 count;
    void **free_list;
} Pool;
void *func_00510AC8(Pool *pool)
{
    void **node = pool->free_list;
    u32 offset, end;
    if (node != 0) {
        pool->free_list = *node;
        pool->count++;
        return node;
    }
    offset = pool->used;
    end = offset + pool->stride;
    if (pool->capacity < end)
        return 0;
    {
        u8 *result = pool->base + offset;
        pool->used = end;
        pool->count++;
        return result;
    }
}
