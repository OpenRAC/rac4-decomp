#include "common.h"

s32 D_002217C8 = 0;
s32 D_002217D8 = 0;

/* PAL: from rac3-decomp's func_L04_003CD280 */
s32 *func_L13_00459968(s32 arg0, s32 arg1, s32 *arg2) {
    switch (arg1) {
    case 0:
        *arg2 = 12;
        return &D_002217C8;
    case 19:
        *arg2 = 12;
        return &D_002217D8;
    default:
        return 0;
    }
}
