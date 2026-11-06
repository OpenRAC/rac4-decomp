#include "common.h"

extern s32 D_0021DF64;

void func_L01_0064F278();                              /* extern */

void func_L01_0064F680(s32 unused0, s32 unused1, s32 unused2, s32 arg3) {
    s32 temp_s0;

    temp_s0 = D_0021DF64;
    if (arg3 < temp_s0) {
        D_0021DF64 = arg3;
    }
    func_L01_0064F278();
    D_0021DF64 = temp_s0;
}
