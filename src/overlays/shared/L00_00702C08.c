#include "common.h"

extern u8 *D_21DFE8;
extern s32 D_21DE10;

// True when the object at D_21DFE8 is in mode 2, or when D_21DE10 holds one of
// the four values at 0x2E..0x31.
s32 func_L00_00702C08(void) {
    s32 r = 0;
    u8 *p = D_21DFE8;

    if ((p != 0 && p[0x1A9] == 2) || (u32)(D_21DE10 - 0x2E) < 4) {
        r = 1;
    }
    return r;
}
