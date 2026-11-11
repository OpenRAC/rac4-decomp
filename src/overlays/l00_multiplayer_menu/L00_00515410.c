#include "common.h"
/* Ported from rac3-decomp's func_L39_004D9610 (src/levels/39_multiplayer_menu/L39_004D7740.c, GPL-3.0), the same code in both games. */

s32 func_L00_004F1548(s32, s32);
s32 func_L00_00515410(s32 arg0, s32 arg1, s32 arg2) {
    s32 ret = func_L00_004F1548(arg0, arg2);
    s32 n = ret;
    if (ret < 0) {
        return ret;
    }
    ret = arg1;
    ret ^= n;
    ret = ret ? -0x6A : n;
    return ret;
}
