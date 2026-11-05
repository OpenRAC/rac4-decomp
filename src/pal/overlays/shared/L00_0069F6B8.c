/* cflags: -O2 -G8 -Wuninitialized -Wreturn-type */
#include "pal/object_callback_resolve.h"

typedef s32 (*Callback)(Object *, f32, f32);
extern char D_00343620[];
extern s32 func_L00_006A3670(void *, s32);
s32 func_L00_0069F6B8(s32 handle, f32 a, f32 b)
{
    s32 result = 0;
    Object *obj = resolve(handle);
    if (obj) {
        u32 type = obj->vtable->getType(obj);
        Callback callback = (Callback)(u32)func_L00_006A3670(D_00343620, (s32)type);
        if (callback)
            result = callback(obj, a, b);
    }
    return result;
}
