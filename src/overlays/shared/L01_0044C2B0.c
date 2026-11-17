#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern s32 func_L00_005A38F8(u128 *, u128 *, s32, u8 *, s32);
extern u8 *D_242358[];

// Finds an object for a slot: the cached one, or a looked-up one; returns it if it matches the slot id.
u8 *func_L01_0044C2B0(u8 *arg0, u128 arg1, u128 arg2) {
    u8 *s0 = *(u8 **)(arg0 + 0xAC);
    u8 *s1 = 0;
    u8 *t;

    if (*(s32 *)(s0 + 0xC) != 0 && (t = *(u8 **)(s0 + 4)) != 0) {
        s1 = t;
    } else if (func_L00_005A38F8(&arg1, &arg2, 1, arg0, 0)) {
        s1 = D_242358[0];
    }
    if (s1 != 0 && (s0[0x12] == 0 || *(s16 *)(s1 + 0xB2) == *(s16 *)(s0 + 8))) {
        return s1;
    }
    return 0;
}
