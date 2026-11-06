/* cflags: -O2 -G8 -Wuninitialized */
#define PAL_TYPED_LOOKUP_TYPE D_00220538
#include "pal/object_typed_lookup.h"

extern void func_00510000(Object *, s32, s32);

s32 func_L00_006A22C0(u32 id, s32 mask, s32 enabled)
{
    s32 result = 0;
    Object *p = getTyped(id);
    if (p) {
        func_00510000(p, mask, enabled);
        result = 1;
    }
    return result;
}
