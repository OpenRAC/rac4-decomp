#include "pal/object_data.h"

/* Read data word 0x08 only for a valid object, data pointer and flag 0x20. */
u32 func_00478908(PalObject *object)
{
    u32 *data;
    if (object != NULL)
        goto present;
empty:
    return 0;
present:
    if (!(object->flags & 0x20))
        goto empty;
    data = object->data;
    if (data == NULL)
        goto empty;
    return data[2];
}
