/* cflags: -O2 -G8 -Wuninitialized -Wreturn-type */
#include "pal/object_callback_resolve.h"

typedef s32 (*Callback)(Object *, f32, f32);
extern char D_00343DB8[];
extern Callback func_L00_006A3750(void *, u32);
s32 func_L00_006A0070(s32 handle, f32 a, f32 b)
{
    s32 result = 0;
    Object *obj = resolve(handle);
    if (obj) {
        u32 type = obj->vtable->getType(obj);
        Callback callback = func_L00_006A3750(D_00343DB8, type);
        if (callback)
            result = callback(obj, a, b);
    }
    return result;
}
