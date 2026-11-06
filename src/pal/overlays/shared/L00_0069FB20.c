/* cflags: -O2 -G8 -Wuninitialized -Wreturn-type */
#include "pal/object_callback_resolve.h"

typedef s32 (*Callback)(Object *, float *, float *);
extern char D_00343668[];
extern s32 func_L00_006A36E0(void *, s32);
s32 func_L00_0069FB20(s32 handle, float *a, float *b)
{
    s32 result = 0;
    Object *obj = resolve(handle);
    if (obj) {
        u32 type = obj->vtable->getType(obj);
        Callback callback = (Callback)(u32)func_L00_006A36E0(D_00343668, (s32)type);
        if (callback)
            result = callback(obj, a, b);
    }
    return result;
}
