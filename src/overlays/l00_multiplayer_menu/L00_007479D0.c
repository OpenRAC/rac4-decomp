#include "common.h"

// Returns 1 when slot 0's flag is set and every other used slot (id != -1) also has its flag set.
s32 func_L00_007479D0(u8 *arg0) {
    s32 r = arg0[0x294] != 0;
    s32 i = 1;
    s32 *p;

    if (r) {
        p = (s32 *)(arg0 + 0x268);
        arg0 += 0x294;
        do {
            if (*p != -1) {
                if (arg0[i] == 0) {
                    r = 0;
                }
            }
            p++;
            i++;
        } while (r && i < 4);
    }
    return r;
}
