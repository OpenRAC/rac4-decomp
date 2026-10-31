#include "common.h"

extern s32 func_005015B0(void);
extern s32 D_00220B50;

// Return 1 if arg matches 8 or the current value; otherwise call the handler.
s32 func_0050D288(void *unused, s32 arg1) {
    s32 var_v0;

    if (arg1 == 8) {
        return 1;
    }
    if (D_00220B50 == arg1) {
        var_v0 = 1;
    } else {
        var_v0 = func_005015B0();
    }
    return var_v0 & 0xFF;
}
