#include "common.h"

extern s32 func_00465338(s32);
extern s32 D_001719C8[];
extern s32 D_0021EE54;

s32 D_0021DB64 = 0;
void (*D_0021F1DC)(void) = 0;

void func_00466078(void)
{
    if (D_001719C8[113] != 2) {
        return;
    }
    if (D_001719C8[115] >= 0) {
        return;
    }
    D_0021DB64 &= -3;
    if (D_001719C8[117] != 0 || D_001719C8[10] != 0) {
        if (D_0021EE54 == 0) {
            if (D_001719C8[121] != 0) {
                D_001719C8[121] = 0;
            }
        }
        func_00465338(24);
    } else {
        if (D_0021EE54 == 0) {
            D_001719C8[121] = 1;
        }
        func_00465338(1);
    }
    if (D_0021F1DC != 0) {
        D_0021F1DC();
        D_0021F1DC = 0;
    }
}
