#include "common.h"
extern s32 func_L01_004F31E0(const u8 *object);

s32 func_L01_004EDFE8(const u8 *object, u8 *context)
{
    *(u32 *)(context + 0x3C) = 0;
    if (func_L01_004F31E0(object))
        return 0;
    return (*(const u8 *const *)(object + 0xB8))[0x20] == 6;
}
