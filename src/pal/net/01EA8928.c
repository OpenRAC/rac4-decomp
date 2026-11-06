#include "common.h"

typedef struct NetHandlePrefix {
    u32 allocated;
    u32 opened;
    u32 opaque8;
    u32 kind;
} NetHandlePrefix;

s32 func_01EA8928(const NetHandlePrefix *handle)
{
    if (handle && handle->allocated && handle->opened && handle->kind < 4u)
        return 1;
    return 0;
}
