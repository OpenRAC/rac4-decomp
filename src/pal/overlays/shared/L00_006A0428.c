/* cflags: -O2 -G8 -Wuninitialized -Wreturn-type */
#include "pal/object_callback_resolve.h"

typedef s32 (*Callback)(Object *, s32, s32);
extern char D_00343B78[];
extern s32 func_L00_006A39A0(void *, s32);
s32 func_L00_006A0428(s32 handle, s32 a, s32 b)
{
    s32 result = 0;
    Object *obj = resolve(handle);
    if (obj) {
        u32 type = obj->vtable->getType(obj);
        Callback callback = (Callback)(u32)func_L00_006A39A0(D_00343B78, (s32)type);
        if (callback)
            result = callback(obj, a, b);
    }
    return result;
}
