#include "common.h"


/* A code for a three-byte state: 0x754B when byte 0 is set, 0x756E when flag is set, 0x7546 when byte 2 is set, else 0x754A or 0 by byte 1. */
s32 func_L00_0064EFA8(u8 *s, s32 flag) {
    if (s[0] != 0) {
        return 0x754B;
    }
    if (flag != 0) {
        return 0x756E;
    }
    if (s[2] == 0) {
        return s[1] ? 0x754A : 0;
    }
    return 0x7546;
}
