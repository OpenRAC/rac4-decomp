#include "common.h"

typedef struct Type1 {
    u64 f0;
    u8 pad08[0x10C];
    s32 f114;
} Type1;

typedef struct Type2 {
    u8 pad00[0x20];
    s32 f20;
    u8 pad24[0x30];
    Type1 *f54;
} Type2;

/* Set the child state when the object is active and the child is clear. */
s32 func_L00_004FF498(Type2 *object)
{
    Type1 *child;
    if (object->f20 == 0) {
        return 1;
    }
    child = object->f54;
    if ((s32)(child->f0 & 1) == 0) {
        child->f114 = 1;
        return 1;
    }
    return 0;
}
