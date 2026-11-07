#include "common.h"

extern s32 func_005664D0(u32);

s32 func_L00_00566D30(u32 arg0) {
    if (arg0 != 0) {
        return func_005664D0(arg0 & 0xFFFF);
    }
    return -1;
}
