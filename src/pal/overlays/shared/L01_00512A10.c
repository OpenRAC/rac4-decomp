#include "common.h"

s32 D_00222838 = 0;
s32 D_00222848 = 0;

/* PAL: from rac3-decomp's func_L04_00313D88 */
void *func_L01_00512A10(s32 arg0, s32 arg1, s32 *arg2) {
    switch (arg1) {
    case 0x13:
        *arg2 = 0xC;
        return &D_00222838;
    case 0x14:
        *arg2 = 8;
        return &D_00222848;
    default:
        return 0;
    }
}
