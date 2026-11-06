#include "common.h"

extern s32 func_00464AF8(s32);
extern s32 D_00171948[];
extern s32 D_0021EDD4;

s32 D_0021DAE4 = 0;
void (*D_0021F15C)(void) = 0;

void func_00465830(void)
{
    if (D_00171948[113] != 2) {
        return;
    }
    if (D_00171948[115] >= 0) {
        return;
    }
    D_0021DAE4 &= -3;
    if (D_00171948[117] != 0 || D_00171948[10] != 0) {
        if (D_0021EDD4 == 0) {
            if (D_00171948[121] != 0) {
                D_00171948[121] = 0;
            }
        }
        func_00464AF8(24);
    } else {
        if (D_0021EDD4 == 0) {
            D_00171948[121] = 1;
        }
        func_00464AF8(1);
    }
    if (D_0021F15C != 0) {
        D_0021F15C();
        D_0021F15C = 0;
    }
}
