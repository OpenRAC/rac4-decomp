/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern s64 func_L01_004B8360(void *object);

u32 func_L01_004B8F68(void *object)
{
    u32 value;
    u32 result;
    u8 disabled;

    value = (u32)*(u8 **)((u8 *)object + 0xAC);
    disabled = ((u8 *)value)[0x458];
    result = 0;
    if (disabled == 0) {
        value = func_L01_004B8360(object) != 0;
        result = value;
    }
    value = result;
    return value;
}
