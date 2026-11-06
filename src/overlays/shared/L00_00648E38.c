#include "common.h"


/* A code for a three-byte state: 0x7548 when byte 0 is set, 0x756E when flag is set, 0x7546 when byte 2 is set, else 0x754A or 0 by byte 1. */
s32 func_L00_00648E38(u8 *s, s32 flag) {
    if (s[0] != 0) {
        return 0x7548;
    }
    if (flag != 0) {
        return 0x756E;
    }
    if (s[2] == 0) {
        return s[1] ? 0x754A : 0;
    }
    return 0x7546;
}
