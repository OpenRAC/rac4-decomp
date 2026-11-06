#include "common.h"

f32 func_L01_005D4C40(s32, s32, s32, s32);
extern s32 D_297680_[];


f32 func_L01_005D4BF0(s32 unused0, s32 unused1, s32 unused2, s32 arg3) {
    s32 temp_a3;

    if (arg3 != -1) {
        temp_a3 = D_297680_[arg3];
        if (temp_a3 != 0) {
            return func_L01_005D4C40(unused0, unused1, unused2, temp_a3);
        }
    }
    return -1.0f;
}
