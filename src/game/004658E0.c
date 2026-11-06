#include "common.h"
extern s32 D_0021DAE4, D_0021EDD4;
typedef struct {
    s32 f0, f4, mode, fC, flags;
    char pad[0x1B0];
    s32 f1C4, f1C8, f1CC, f1D0, f1D4, f1D8, f1DC, f1E0, f1E4;
} State;
extern State D_00171948;
extern void func_00464AF8(s32);
void func_004658E0(void)
{
    D_0021DAE4 &= ~0x200;
    if (!D_0021EDD4 && D_00171948.f1C4 == 2 && D_00171948.f1CC < 0) {
        if (D_00171948.f1D4 || (D_00171948.mode == 2 && D_00171948.flags)) {
            D_00171948.f1E4 = 0;
            func_00464AF8(3);
        } else {
            D_00171948.f1E4 = 1;
            func_00464AF8(1);
        }
    }
}
