#include "common.h"

/* Calls func_0048A9F8 on each 0x50-byte record of D_355DC0 (0xF0 bytes), clearing the byte at +8 of each after the call. */
extern void func_0048A9F8(s32, void *);
extern u8 D_355DC0[];
s32 D_0021F358 = 0;

void func_00489F30(s32 arg0) {
    u8 *s0;
    u8 *s2;

    D_0021F358 = 3;
    s0 = D_355DC0;
    s2 = s0 + 0xF0;
    do {
        func_0048A9F8(arg0, s0);
        s0[8] = 0;
        s0 += 0x50;
    } while ((s32)s0 < (s32)s2);
}
