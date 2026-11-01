#include "pal/object_data.h"

extern u8 *D_003367B8[];

/* Search the object table before using the object data fallback. */
void *func_00476F70(PalObject *object)
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
        if (entry != NULL && object == *(PalObject **)(entry + 0x2EF0))
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
