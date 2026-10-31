#include "common.h"

extern s32 func_005015B0(s32 arg0, s32 arg1);
s32 D_00220B58 = 0;
extern s32 D_00220B50;
// Return 1 when arg1 equals D_00220B58, else 1 when it equals D_00220B50, else the result of func_005015B0 masked to a byte.
s32 func_0050D3B8(s32 arg0, s32 arg1) {
    s32 var_v0;

    if (arg1 != D_00220B58) {
        if (D_00220B50 == arg1) {
            var_v0 = 1;
        } else {
            var_v0 = func_005015B0(arg0, arg1);
        }
        return var_v0 & 0xFF;
    }
    return 1;
}
