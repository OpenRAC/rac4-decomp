#include "common.h"

extern u8 *D_222D14;
extern u8 *D_222D30;

// Counts the 0x100-byte entries tagged 0x2075 whose linked block has a nonzero flag byte at 0x2E7.
s32 func_L01_004CFB98(void) {
    u8 *p;
    s32 n = 0;

    for (p = D_222D14; p != D_222D30; p += 0x100) {
        if (*(s16 *)(p + 0xBC) == 0x2075) {
            if (*(u8 *)(*(u8 **)(p + 0xAC) + 0x2E7) != 0) {
                n++;
            }
        }
    }
    return n;
}
