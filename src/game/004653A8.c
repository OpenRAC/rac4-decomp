#include "common.h"

extern s32 func_00464AF8(s32);
extern s32 D_00171948[];
extern s32 D_0021DAE4;

s32 D_0021F1D0 = -1;
void (*D_0021F1E8)(void) = 0;

void func_004653A8(void)
{
    if (D_00171948[113] != 2) {
        return;
    }
    if (D_00171948[115] >= 0) {
        return;
    }
    if (D_00171948[117] != 0) {
        func_00464AF8(20);
    } else {
        D_00171948[108] = 0;
        ((u16 *)D_00171948)[12] = 0;
        if (D_0021DAE4 & 0x1000) {
            ((u16 *)D_00171948)[12] = D_0021F1D0;
            D_0021DAE4 &= -0x1001;
            D_0021F1D0 = -1;
        }
        func_00464AF8(18);
    }
    if (D_0021F1E8 != 0) {
        D_0021F1E8();
        D_0021F1E8 = 0;
    }
}
