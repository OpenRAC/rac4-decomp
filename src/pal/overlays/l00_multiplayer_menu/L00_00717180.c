/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern s32 func_L00_006A0EA0(s32 handle, u32 value);

/* Invoke the object's callback when its handle is valid. */
s32 func_L00_00717180(void *object, u32 value)
{
    s32 handle = *(s32 *)((u8 *)object + 0x14);

    if (handle != 0xFFFFFFFF) {
        return func_L00_006A0EA0(handle, value);
    }
    return 0;
}
