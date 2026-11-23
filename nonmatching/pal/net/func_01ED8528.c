/* Not matching yet: PAL WIP; main net.text 0x01ED8528, 96B. Not part of the build. */
/*
 * Guarded-shift draft remains92B/native96B: increment occupies native NOP, sentinel
 * materialization and branch/return placement differ. No missing source or new runtime
 * shift-domain promise is inferred.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 81bd146467e35955b919a65082dae8c6b5f156d4c29713d0b121948ebce8f380
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01ED8528 nonmatching/pal/net/func_01ED8528.c --diff
 */
#include "common.h"

/* Finds a set bit at or after the stored position, retaining the native end marker. */
s32 func_01ED8528(u8 *p) {
    u16 bit;
    u32 mask;
    u32 shifted;

    if (p == 0) return 0xFFFF;
    bit = *(u16 *)(p + 0x10);
    mask = *(u32 *)(p + 0xC);
    while (bit < 0x20) {
        shifted = mask >> bit;
        if (shifted & 1) {
            *(u16 *)(p + 0x10) = bit;
            return bit;
        }
        if (shifted == 0) return 0xFFFF;
        bit++;
    }
    *(u16 *)(p + 0x10) = 0xFFFF;
    return 0xFFFF;
}
