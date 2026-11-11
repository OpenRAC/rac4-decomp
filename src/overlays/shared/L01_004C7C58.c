/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern s64 func_L01_004C80A8(void *object);

u32 func_L01_004C7C58(void *object)
{
    u32 value;
    u32 result;
    u8 disabled;

    value = (u32)*(u8 **)((u8 *)object + 0xAC);
    disabled = ((u8 *)value)[0x408];
    result = 0;
    if (disabled == 0) {
        value = func_L01_004C80A8(object) != 0;
        result = value;
    }
    value = result;
    return value;
}
