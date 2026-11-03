#include "common.h"
extern s32 D_0021EE54, D_0021EE58;
s32 D_0021F638 = 0;
extern s32 func_004990A0(s32, s32), func_00506BB8(void);
s32 func_00499120(s32 mode)
{
    s32 result;
    if (D_0021EE54 != 1) {
        D_0021F638 = 0;
        result = func_004990A0(0, mode);
        if (!D_0021EE54 && D_0021EE58 == 1) {
            s32 other = func_004990A0(1, mode);
            if ((other && other < result) || !result) {
                result = other;
                D_0021F638 = 1;
            }
        }
    } else {
        D_0021F638 = func_00506BB8();
        result = func_004990A0(func_00506BB8(), mode);
    }
    return result;
}
