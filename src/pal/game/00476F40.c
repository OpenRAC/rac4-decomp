#include "pal/object_data.h"

/* Read data word 0x10 when the object has flag 0x20 set. */
u32 func_00476F40(PalObject *object)
{
    if (object != NULL)
        goto present;
empty:
    return 0;
present:
    if (!(object->flags & 0x20))
        goto empty;
    return object->data[4];
}
