#include "common.h"

extern s32 func_005015B0(s32 arg0, s32 arg1);
s32 D_00220474 = 0;
extern s32 D_00220468;
// Return 1 when arg1 equals D_00220474 or D_00220468, else the helper result masked to a byte.
s32 func_L00_006A6260(s32 arg0, s32 arg1) {
    s32 var_v0;

    if (arg1 != D_00220474) {
        if (D_00220468 == arg1) {
            var_v0 = 1;
        } else {
            var_v0 = func_005015B0(arg0, arg1);
        }
        return var_v0 & 0xFF;
    }
    return 1;
}
