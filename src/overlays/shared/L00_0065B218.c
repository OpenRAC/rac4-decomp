#include "common.h"

extern void func_L00_005B0ED8(s32, s32, s32, s32);
extern void func_L00_006796D0(s32, s32, s32);
extern s32 D_004CAC20[];
extern s32 D_0021DDB4;
extern s32 D_001DFCF4[];
extern s32 D_001D3F44[];

void func_L00_0065B218(void) {
    if (D_004CAC20[0] != 0 && D_0021DDB4 == 3) {
        func_L00_006796D0(D_004CAC20[0], D_001DFCF4[0], D_001D3F44[0] << 11);
        func_L00_005B0ED8(0, 0, 0, 0x60);
    }
}
