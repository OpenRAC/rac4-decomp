#include "common.h"
typedef struct Link {
    u8 unused[0x1C];
    const struct Link *parent;
} Link;
s32 func_L01_00571388(const Link *object, const Link *target)
{
    if (!target)
        return 1;
    if (!object || object == target)
        return 0;
    while (object) {
        if (object == target)
            return 1;
        object = object->parent;
    }
    return 0;
}
