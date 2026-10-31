#include "common.h"

extern void func_00159A00(s32 arg0, s32 arg1, s32 arg2);
extern u8 D_1C2040[];

// Calls func_00159A00 on D_1C2040, then copies a word from 0x1E0 bytes back into each of 21 records starting at D_1C2040 + 0xC620.
void func_00159A50(void) {
    u8 *base;
    u8 *p;
    s32 n;

    base = D_1C2040;
    func_00159A00(0x3E9, 0x1A, (s32)base);
    n = 0x14;
    p = base + 0xC620;
    do {
        n -= 1;
        *(s32 *)p = *(s32 *)(p - 0x1E0);
        p += 0x18;
    } while (n >= 0);
}
