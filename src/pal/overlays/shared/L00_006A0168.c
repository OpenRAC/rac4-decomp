/* cflags: -O2 -G8 -Wuninitialized -Wreturn-type */
#define PAL_TYPED_LOOKUP_TYPE D_00220488
#include "pal/object_typed_lookup.h"

typedef s32 (*Callback)(Object *, f32);
extern Callback func_L00_006A3840(void *, u32);
extern char D_00343DD8[];
static inline Callback handler(u32 kind)
{
    return func_L00_006A3840(D_00343DD8, kind);
}
s32 func_L00_006A0168(u32 id, f32 amount)
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
