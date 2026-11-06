/* cflags: -O2 -G8 -Wuninitialized -Wreturn-type */
#include "pal/object_callback_resolve.h"

typedef s32 (*Callback)(Object *, u32, u32);
extern char D_00343C50[];
extern s32 func_L00_006A3A80(void *, s32);
s32 func_L00_006A0710(s32 handle, u32 a, u32 b)
{
    s32 result = 0;
    Object *obj = resolve(handle);
    if (obj) {
        u32 type = obj->vtable->getType(obj);
        Callback callback = (Callback)(u32)func_L00_006A3A80(D_00343C50, (s32)type);
        if (callback)
            result = callback(obj, a, b);
    }
    return result;
}
