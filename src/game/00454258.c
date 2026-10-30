#include "common.h"

// Decode variable-length encoding from byte array
s32 func_00454258(u8 *arg0, s32 arg1, s32 *arg2) {
    u8 byte1 = arg0[arg1];
    s32 result = 0;
    *arg2 = byte1;

    if (byte1 & 0x80) {
        u8 byte2 = arg0[arg1 + 1];
        *arg2 = ((byte1 & 0x7F) << 8) | byte2;
        *arg2 += 0x7F;
        result = 1;
    }

    return result;
}
