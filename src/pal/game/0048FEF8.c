#include "pal/object_data.h"

/* Read data word 0x28 only for a valid object, data pointer and flag 0x20. */
u32 func_0048FEF8(PalObject *object)
{
    u32 *data;
    if (object == NULL)
        return 0;
    data = object->data;
    if (data == NULL)
        return 0;
    if (object->flags & 0x20)
        return data[10];
    return 0;
}
