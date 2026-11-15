/* cflags: -mno-split-addresses */
#include "common.h"

extern u8 *D_222990;

// Walks the parent chain of object arg0 and reports whether its flags are set.
s32 func_L01_00524428(s32 arg0) {
    u8 *obj;
    s32 next;
    s32 r;
    s32 flagged;

    obj = *(u8 **)(D_222990 + arg0 * 0x20 + 0x1C);
    next = *(s32 *)(obj + 0xDC);
    if (next >= 0) {
        r = 0;
        if (func_L01_00524428(next) != 0) {
            if (obj[0x104] != 0) {
                r = obj[0x106] != 0;
            }
        }
        return r;
    }
    flagged = 0;
    if (obj[0x104] != 0) {
        flagged = obj[0x106] != 0;
    }
    return flagged;
}
