/* cflags: -O2 -G8 -fopt-stack -Wuninitialized */
#include "pal/object_callback_resolve.h"

typedef s32 (*Callback)(Object *, u32);
extern char D_003438F0[];
extern s32 func_L00_006A37D0(void *, s32);

/* Resolve a supported object and invoke the callback registered for its type. */
s32 func_L00_0069FF88(s32 handle, u32 value)
{
    s32 result = 0;
    Object *object = resolve(handle);

    if (object) {
        u32 type = object->vtable->getType(object);
        Callback callback = (Callback)func_L00_006A37D0(D_003438F0, (s32)type);
        if (callback)
            result = callback(object, value);
    }
    return result;
}
