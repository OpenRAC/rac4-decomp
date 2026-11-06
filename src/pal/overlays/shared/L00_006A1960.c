/* cflags: -O2 -G8 -Wuninitialized */
#include "pal/object_typed_lookup.h"

extern u32 D_00220524;

extern s32 func_0050D870(Object *, s32, s32);

s32 func_L00_006A1960(u32 id, u32 child, s32 index)
{
    s32 result = 0;
    Object *p = getTyped(id, &D_00220524);
    if (p)
        result = func_0050D870(p, (s32)child, index);
    return result;
}
