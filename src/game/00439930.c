#include "common.h"

extern void func_00159870(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 D_20B9C0_[];
#define D_20B9C0 (D_20B9C0_[0])

// Clears bit 0 of D_20B9C0 after calling func_00159870 with 0xBFE87362 and 0xB; returns 1 if that bit was set, else 0.
s32 func_00439930(void) {
    if (D_20B9C0 & 1) {
        func_00159870(0xBFE87362, 0xB, 0, 0, 0, 0, 0);
        D_20B9C0 &= ~1;
        return 1;
    }
    return 0;
}
