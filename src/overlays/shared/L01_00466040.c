#include "common.h"

extern s32 func_L00_005E6560();

s32 func_L01_00466040(u8 *arg0, s32 arg1) {
    s32 ret = 0;
    u8 *base = *(u8 **)(arg0 + 0xAC) + 0x20;
    s32 *p = (s32 *)(base + arg1 * 4);
    if (func_L00_005E6560(*p) == 0) {
        ret = *p;
    }
    return ret;
}
