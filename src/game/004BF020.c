#include "common.h"

extern u8 D_1F87F0[];

/* Maps arg0 (0..4) to a value, then returns whether byte 9 of that 0xC-byte entry is nonzero. */
s32 func_004BF020(s32 arg0) {
    s32 a1 = -1;
    s32 r;
    switch (arg0) {
    case 0:
        a1 = 0x25;
        break;
    case 1:
        a1 = 0xF;
        break;
    case 2:
        a1 = 0x17;
        break;
    case 3:
        a1 = 0x26;
        break;
    case 4:
        a1 = 0x27;
        break;
    }
    r = 0;
    if (a1 > 0) {
        r = D_1F87F0[a1 * 12 + 9] != 0;
    }
    return r;
}
