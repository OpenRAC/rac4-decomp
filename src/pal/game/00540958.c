#include "common.h"

typedef struct { u8 pad00[0x67]; u8 kind; } Inner;
typedef struct { u8 pad00[0x2B0]; Inner *inner; } Link;
typedef struct { u8 pad00[0x2EF4]; Link *link; } Object;

s32 func_00540958(Object *object)
{
    s32 kind;
    if (object->link == NULL) {
        return 0;
    }
    kind = object->link->inner->kind;
    if ((u32)(kind - 7) < 2 || kind == 10) {
        return 1;
    }
    return 0;
}
