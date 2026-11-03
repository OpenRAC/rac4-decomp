#include "common.h"
extern s32 D_0021DB64, D_0021EE54;
typedef struct {
    s32 f0, f4, mode, fC, flags;
    char pad[0x1B0];
    s32 f1C4, f1C8, f1CC, f1D0, f1D4, f1D8, f1DC, f1E0, f1E4;
} State;
extern State D_001719C8;
extern void func_00465338(s32);
void func_00466128(void)
{
    D_0021DB64 &= ~0x200;
    if (!D_0021EE54 && D_001719C8.f1C4 == 2 && D_001719C8.f1CC < 0) {
        if (D_001719C8.f1D4 || (D_001719C8.mode == 2 && D_001719C8.flags)) {
            D_001719C8.f1E4 = 0;
            func_00465338(3);
        } else {
            D_001719C8.f1E4 = 1;
            func_00465338(1);
        }
    }
}
