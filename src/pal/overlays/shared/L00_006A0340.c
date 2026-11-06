/* cflags: -O2 -G8 -Wuninitialized -Wreturn-type */
#include "pal/object_typed_lookup.h"

extern u32 D_00220488;

typedef s32 (*Callback)(Object *, f32);
extern s32 func_L00_006A38C0(void *, s32);
extern char D_00343B30[];
static inline Callback handler(u32 kind)
{
    return (Callback)(u32)func_L00_006A38C0(D_00343B30, (s32)kind);
}
s32 func_L00_006A0340(u32 id, f32 amount)
{
    s32 result = 0;
    Object *p = getTyped(id, &D_00220488);
    if (p) {
        Callback callback = handler(p->vtable->getType(p));
        if (callback)
            result = callback(p, amount);
    }
    return result;
}
