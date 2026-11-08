/* Not matching yet: SIZE ours 84 / retail 104 (tools/try_func.py func_01EBE1B8 --diff). Not part of the build. */
#include "common.h"

// Copy the 8-byte body and the 0x10 word of the record at 0x8.
s32 func_01EBE1B8(s32 a0, u8 *src, u8 *dst, s32 *outValue) {
    u8 *record = 0;
    u64 value;
    s32 word;

    if (a0 == 0) {
        return 0xD2F2;
    }
    if (src != 0) {
        value = *(u64 *)(src + 0x8);
        *(u64 *)dst = value;
        word = *(s32 *)(src + 0x10);
    } else {
        if (a0 != -0x2C) {
            record = *(u8 **)(a0 + 0x38);
        }
        if (record == 0) {
            return 3;
        }
        value = *(u64 *)(record + 0x8);
        *(u64 *)dst = value;
        word = *(s32 *)(record + 0x10);
    }
    *outValue = word;
    return 0;
}
