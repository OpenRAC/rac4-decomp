#include "common.h"

// Folds arg1 bytes at arg0 into a bit-serial 16-bit checksum (poly 0x1F45).
u32 func_00468B78(u8 *arg0, s32 arg1) {
    u8 *end = arg0 + arg1;
    u32 crc = 0xEDB88320;
    s32 i;

    if (arg0 < end) {
        do {
            crc ^= *arg0 << 8;
            arg0++;
            i = 7;
            do {
                if (crc & 0x8000) {
                    crc = (crc << 1) ^ 0x1F45;
                } else {
                    crc = crc << 1;
                }
                i--;
            } while (i >= 0);
        } while (arg0 < end);
    }
    return crc & 0xFFFF;
}
