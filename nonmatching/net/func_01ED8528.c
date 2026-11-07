/* Not matching yet: SIZE ours 108 / retail 96 (tools/try_func.py func_01ED8528 --diff). Not part of the build. */
#include "common.h"

// Find the first set bit from the stored bit position; 0xFFFF marks the end.
s32 func_01ED8528(u8 *p) {
    u16 bit;
    u32 mask;

    if (p == 0) {
        return 0xFFFF;
    }
    bit = *(u16 *)(p + 0x10);
    if (bit >= 0x20) {
        *(u16 *)(p + 0x10) = -1;
        return 0xFFFF;
    }
    mask = *(u32 *)(p + 0xC);
    for (;;) {
        if ((mask >> bit) & 1) {
            *(u16 *)(p + 0x10) = bit;
            return bit;
        }
        if ((mask >> bit) == 0) {
            return 0xFFFF;
        }
        bit++;
        if (bit >= 0x20) {
            *(u16 *)(p + 0x10) = -1;
            return 0xFFFF;
        }
    }
}
