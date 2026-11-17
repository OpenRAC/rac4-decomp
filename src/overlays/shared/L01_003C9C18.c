#include "common.h"

extern s32 func_L00_00702698();
extern u8 D_1F87F0[];

/* Tests whether the object's linked slot entry is active. */
s32 func_L01_003C9C18(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0xAC);
    s32 x;
    s32 sp;
    s32 idx;

    if (!p[0x70]) {
        return 0;
    }
    if (*(s32 *)(p + 0x6C) < 0) {
        return 0;
    }
    x = *(s32 *)(p + 0x8C);
    if (x != 0) {
        idx = func_L00_00702698(x, &sp);
        if (D_1F87F0[idx * 0xC + ((sp - 1) % 20) * 0x304 + 9] == 0) {
            return 0;
        }
    }
    return 1;
}
