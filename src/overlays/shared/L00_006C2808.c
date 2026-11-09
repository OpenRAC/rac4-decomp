#include "common.h"

typedef int u128 __attribute__((mode(TI)));
s32 func_L00_006C21F0(void *, s32);

/* Step a 32-entry ring index back up to N times, copying the selected quadword to +0xA0. */
void func_L00_006C2808(u8 *p) {
    s32 n;
    s32 i;

    n = p[0x266D] ? 16 : 1;
    for (i = 0; i < n; i++) {
        if (func_L00_006C21F0(p, i) == 1) return;
        if (*(s32 *)(p + 0x2C7C) >= 2) {
            *(s32 *)(p + 0x2C7C) -= 1;
            *(s32 *)(p + 0x2C78) = (*(s32 *)(p + 0x2C78) + 31) % 32;
        }
        *(u128 *)(p + 0xA0) = *(u128 *)(p + *(s32 *)(p + 0x2C78) * 16 + 0x26F0);
    }
}
