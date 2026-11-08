/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

typedef char PointerWordSize[(sizeof(u32) == sizeof(void *)) ? 1 : -1];
typedef char ScalarResultSize[(sizeof(s64) == 8) ? 1 : -1];

extern s64 func_L01_004970E8(void *object);

u32 func_L01_00497258(void *object)
{
    u32 value;
    u32 result;
    u8 disabled;

    /* Read through the real linked-block address before reusing its storage. */
    value = (u32)*(u8 **)((u8 *)object + 0xAC);
    disabled = ((u8 *)value)[0x458];
    result = 0;
    if (disabled == 0) {
        value = func_L01_004970E8(object) != 0;
        result = value;
    }
    value = result;
    return value;
}
