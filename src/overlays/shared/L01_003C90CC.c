#include "common.h"

s32 D_00220B38 = 0;

/* Store 8 into the pointed word and return the address of a global. */
s32 *func_L01_003C90CC(s32 arg0, s32 arg1, s32 *arg2) {
    *arg2 = 8;
    return &D_00220B38;
}
