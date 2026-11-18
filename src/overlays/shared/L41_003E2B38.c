#include "common.h"

extern u8 *D_222794;
extern u8 *D_2227B0;

// Scans 0x100-byte records tagged 0x266E whose linked block's first byte equals arg0.
u8 *func_L41_003E2B38(s32 arg0) {
    u8 *p;
    u8 *r = 0;

    for (p = D_222794; p < D_2227B0; p += 0x100) {
        if (*(s16 *)(p + 0xBC) == 0x266E && *(u8 **)(p + 0xAC) != 0 &&
            **(u8 **)(p + 0xAC) == arg0) {
            r = p;
            break;
        }
    }
    return r;
}
