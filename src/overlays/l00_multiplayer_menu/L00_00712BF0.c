#include "common.h"

// Stores a clamped entry count, copies the entry pointers, calls the method of those not of type 3, and selects the first entry.
s32 func_L00_00712BF0(u8 *a0, s32 a1, u8 **a2) {
    s32 i;

    *(s32 *)(a0 + 0x120) = a1;
    if (a1 > 0x100) {
        *(s32 *)(a0 + 0x120) = 0x100;
    }
    for (i = 0; i < *(s32 *)(a0 + 0x120); i++) {
        u8 *e = a2[i];
        if (e != 0) {
            *(u8 **)(a0 + 0x124 + i * 4) = e;
            if (*(s32 *)(e + 4) != 3) {
                (*(void (**)(u8 *, s32, s32))(*(u8 **)(e + 0x58) + 0x20))(e, 0, 0);
            }
        } else {
            *(u8 **)(a0 + 0x124 + i * 4) = 0;
        }
    }
    if (*(s32 *)(a0 + 0x120) > 0) {
        *(s32 *)(a0 + 0x524) = 0;
    } else {
        *(s32 *)(a0 + 0x524) = -1;
    }
    *(s32 *)(a0 + 0x528) = *(s32 *)(a0 + 0x524);
    return *(s32 *)(a0 + 0x120);
}
