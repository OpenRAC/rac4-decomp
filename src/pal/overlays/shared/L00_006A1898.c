/* cflags: -O2 -G8 -Wuninitialized */
#define PAL_TYPED_LOOKUP_TYPE D_00220524
#include "pal/object_typed_lookup.h"

extern s32 func_0050DB58(Object *, u32, s32);

s32 func_L00_006A1898(u32 id, u32 child, s32 index)
{
    s32 result = 0;
    Object *p = getTyped(id);
    if (p)
        result = func_0050DB58(p, child, index);
    return result;
}
