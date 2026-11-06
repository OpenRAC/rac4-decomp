/* cflags: -O2 -G8 -Wuninitialized -Wreturn-type */
#define PAL_TYPED_LOOKUP_TYPE D_00220488
#include "pal/object_typed_lookup.h"

typedef s32 (*Callback)(Object *, f32);
extern s32 func_L00_006A38C0(void *, s32);
extern char D_00343818[];
static inline Callback handler(u32 kind)
{
    return (Callback)(u32)func_L00_006A38C0(D_00343818, (s32)kind);
}
s32 func_L00_006A0CD0(u32 id, f32 amount)
{
    s32 result = 0;
    Object *p = getTyped(id);
    if (p) {
        Callback callback = handler(p->vtable->getType(p));
        if (callback)
            result = callback(p, amount);
    }
    return result;
}
