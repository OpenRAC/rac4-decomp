/* cflags: -O2 -G8 -fopt-stack -Wuninitialized -Wreturn-type */
#include "pal/object_callback_resolve.h"

typedef s32 (*Callback)(Object *, u8 *);
extern char D_00343788[];
extern s32 func_L00_006A3B60(void *, s32);

/* Resolve a supported object and invoke the callback registered for its type. */
s32 func_L00_006A0AF8(s32 handle, u8 *value)
{
    s32 result = 0;
    Object *object = resolve(handle);

    if (object) {
        u32 type = object->vtable->getType(object);
        Callback callback = (Callback)(u32)func_L00_006A3B60(D_00343788, (s32)type);
        if (callback)
            result = callback(object, value);
    }
    return result;
}
