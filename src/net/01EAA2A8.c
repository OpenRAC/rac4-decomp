/* cflags: @ee296 -O2 -G0 */
#include "common.h"

// Reads or writes a 1-2 byte variable-length u16 value at the cursor of a bounded buffer.
s32 func_01EAA2A8(s32 op, u8 *p, u16 *data) {
    u8 *read;
    u8 *cur;
    u16 v;

    if (*(s32 *)(p + 0x10) != 0) {
        return 0;
    }
    read = *(u8 **)(p + 0x4);
    if (*(u8 **)(p + 0x8) >= read) {
        *(s32 *)(p + 0x10) = 2;
        return 0;
    }
    if (*(u8 **)(p + 0x8) == 0) {
        *(s32 *)(p + 0x10) = 2;
        return 0;
    }
    if ((u32)(read - *(u8 **)(p + 0x8)) < 4) {
        *(s32 *)(p + 0x10) = 8;
        return 0;
    }
    if (op == 1) {
        v = *data;
        if (v >= 0x7FFF) {
            *(s32 *)(p + 0x10) = 2;
            return 0;
        }
        if (v >= 0x80) {
            *(*(u8 **)(p + 0x8)) = (v >> 8) | 0x80;
            *(u8 **)(p + 0x8) = *(u8 **)(p + 0x8) + 1;
        }
        *(*(u8 **)(p + 0x8)) = *data;
    } else if (op == 2) {
        cur = *(u8 **)(p + 0x8);
        v = *cur;
        *data = v;
        if (v & 0x80) {
            *(u8 **)(p + 0x8) = cur + 1;
            *data = (v << 8) & 0x7FFF;
            *data = *data | *(cur + 1);
        }
        if (*data >= 0x7FFF) {
            *(s32 *)(p + 0x10) = op;
            return 0;
        }
    }
    *(u8 **)(p + 0x8) = *(u8 **)(p + 0x8) + 1;
    return 1;
}
