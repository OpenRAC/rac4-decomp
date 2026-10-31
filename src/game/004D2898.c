#include "common.h"

extern s32 func_00505B20(void);
extern u8 D_31B6B0[];

// Return 1 unless arg0 is 4; then return whether the +0xC word of the current 0x1C-byte entry is nonzero.
s32 func_004D2898(s32 arg0) {
    u8 *entry;

    if (arg0 == 4) {
        entry = D_31B6B0 + func_00505B20() * 0x1C;
        return *(s32 *)(entry + 0xC) != 0;
    }
    return 1;
}
