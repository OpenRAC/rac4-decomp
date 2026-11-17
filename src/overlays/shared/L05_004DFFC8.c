#include "common.h"

// Returns 0 when the +0x67 byte is 7..11 or the state byte at +0x20 is 3, 5, 6 or 7; otherwise 1.
s32 func_L05_004DFFC8(u8 *a0) {
    s32 a1;
    s32 v;
    s32 s;

    a1 = 1;
    v = a0[0x67];
    if (v < 0xC) {
        if (v >= 7) {
            a1 = 0;
            goto done;
        }
    }
    s = a0[0x20];
    if (s == 7 || s == 3 || s == 5 || s == 6) {
        a1 = 0;
    }
done:
    return a1;
}
