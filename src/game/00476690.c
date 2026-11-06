
#include "common.h"

/* Partial object layout used by the PAL data accessors. */
typedef struct {
    u8 pad00[0x34];
    u16 flags;
    u8 pad36[0x76];
    u32 *data;
} ObjectData;


extern u8 *D_003367B8[];

/* Search the object table before using the object data fallback. */
void *func_00476690(ObjectData *object)
{
    s32 i;
    u8 *entry;
    u8 **cursor;
    u32 *data;
    if (object == NULL)
        goto empty;
    cursor = D_003367B8;
    entry = *cursor;
    for (i = 0; i < 10; i++, entry = *cursor) {
        cursor++;
        if (entry != NULL && object == *(ObjectData **)(entry + 0x2EF0))
            goto found;
    }
    data = object->data;
    if (data == NULL)
        goto empty;
    if (object->flags & 0x20)
        goto fallback;
empty:
    return NULL;
found:
    return entry + 0x1F9C;
fallback:
    return (void *)data[0];
}
