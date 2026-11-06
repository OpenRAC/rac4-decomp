#include "common.h"

extern s32 func_L00_0069D6C0(s32 handle, u32 value);

s32 func_L00_00711D60(u8 *object, u32 value)
{
    s32 result = 0;
    s32 handle = *(s32 *)(object + 0x14);

    if (handle != 0)
        result = func_L00_0069D6C0(handle, value);
    handle = *(s32 *)(object + 0x5C);
    if (handle != 0)
        result |= func_L00_0069D6C0(handle, value);
    return result != 0;
}
