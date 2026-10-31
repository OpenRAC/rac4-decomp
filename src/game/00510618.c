#include "common.h"

extern s32 func_005015B0(s32 arg0, s32 arg1);
extern s32 D_00220B50;
s32 D_00220B70 = 0;

// Return 1 if arg1 equals the gp-held value or the current value at D_00220B50; otherwise call the handler.
s32 func_00510618(s32 arg0, s32 arg1) {
    s32 var_v0;

    if (arg1 != D_00220B70) {
        if (D_00220B50 == arg1) {
            var_v0 = 1;
        } else {
            var_v0 = func_005015B0(arg0, arg1);
        }
        return var_v0 & 0xFF;
    }
    return 1;
}
