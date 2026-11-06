/* cflags: -O2 -G8 -Wuninitialized */
#include "pal/object_typed_lookup.h"

extern u32 D_00220524;

extern void func_0050DEB8(void *, u32, s32);

s32 func_L00_006A2108(u32 id, s32 mask, s32 enabled)
{
    s32 result = 0;
    Object *p = getTyped(id, &D_00220524);
    if (p) {
        func_0050DEB8(p, (u32)mask, enabled);
        result = 1;
    }
    return result;
}
