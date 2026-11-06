#include "common.h"

s32 func_L01_0046D588(const u8 *object)
{
    s32 result = 0;
    if ((object[0x217] & 0x80) != 0) {
        result = 1;
        if ((*(const u64 *)(object + 0x228) & 0x0000FFFF00000000UL) != 0)
            result = 0;
    }
    return result;
}
