#include "common.h"

s32 func_L01_00633030(s32 arg0);
extern u8 D_0020FF20[];

void func_L01_00633070(s32 arg0) {
    D_0020FF20[arg0] = 1;
    if (arg0 == 8) {
        func_L01_00633030(0x10);
    }
}
