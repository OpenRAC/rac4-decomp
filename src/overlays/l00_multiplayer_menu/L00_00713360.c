/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern s32 func_0069D6C0(s32 handle, u32 value);

s32 func_L00_00713360(void *object, u32 value)
{
    s32 handle = *(s32 *)((u8 *)object + 0x14);

    if (handle != 0xFFFFFFFF) {
        return func_0069D6C0(handle, value);
    }
    return 0;
}
