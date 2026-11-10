#include "common.h"

extern s32 func_00465338(s32);
extern s32 D_001719C8[];
extern s32 D_0021DB64;

s32 D_0021F1D0 = -1;
void (*D_0021F1E8)(void) = 0;

void func_004653A8(void)
{
    if (D_001719C8[113] != 2) {
        return;
    }
    if (D_001719C8[115] >= 0) {
        return;
    }
    if (D_001719C8[117] != 0) {
        func_00465338(20);
    } else {
        D_001719C8[108] = 0;
        ((u16 *)D_001719C8)[12] = 0;
        if (D_0021DB64 & 0x1000) {
            ((u16 *)D_001719C8)[12] = D_0021F1D0;
            D_0021DB64 &= -0x1001;
            D_0021F1D0 = -1;
        }
        func_00465338(18);
    }
    if (D_0021F1E8 != 0) {
        D_0021F1E8();
        D_0021F1E8 = 0;
    }
}
