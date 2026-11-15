#include "common.h"

s32 func_L00_00536248(u8 **cursor, s32 *indefinite, s64 *out, s32 remaining) {
    s32 previous = remaining;
    u8 *p = *cursor;
    u64 value = 0;
    u32 header;
    s32 count;
    remaining = (s32)((u32)remaining - 1U);
    if (previous <= 0) goto fail;
    if (*p != 0x80) {
        *indefinite = 0;
        goto decode;
    }
    *indefinite = 1;
    p++;
    goto check;
decode:
    header = *p++;
    count = header & 0x7F;
    if (header & 0x80) {
        if ((u32)count > sizeof(value)) goto fail;
        remaining--;
        if (remaining == -1) goto fail;
        while (count-- > 0) {
            value <<= 8;
            value |= *p++;
            if (--remaining == -1) goto fail;
        }
    } else {
        value = count;
    }
check:
    if ((s64)value >= 0) goto success;
fail:
    return 0;
success:
    *cursor = p;
    *out = (s64)value;
    return 1;
}
