/* cflags: -O2 -G8 -Wuninitialized */
#define PAL_TYPED_LOOKUP_TYPE D_00220538
#include "pal/object_typed_lookup.h"

extern s32 func_00510060(Object *, s32, s32);

s32 func_L00_006A21F8(u32 id, s32 mask, s32 enabled)
{
    s32 result = 0;
    Object *p = getTyped(id);
    if (p) {
        func_00510060(p, mask, enabled);
        result = 1;
    }
    return result;
}
