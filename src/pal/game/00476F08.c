#include "pal/object_data.h"

/* Read data word 0x3C only for a valid object, data pointer and flag 0x20. */
u32 func_00476F08(PalObject *object)
{
    u32 *data;
    if (object == NULL)
        return 0;
    data = object->data;
    if (data == NULL)
        return 0;
    if (object->flags & 0x20)
        return data[15];
    return 0;
}
