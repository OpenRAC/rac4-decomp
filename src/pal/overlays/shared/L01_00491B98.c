#include "common.h"

s32 D_00221CA0 = 0;
s32 D_00221CA8 = 0;
s32 D_00221CB8 = 0;

/* PAL: from rac3-decomp's func_L01_003506E0 */
void *func_L01_00491B98(s32 arg0, s32 arg1, s32 *arg2) {
    switch (arg1) {
    case 0:
        *arg2 = 4;
        return &D_00221CA0;
    case 0x13:
        *arg2 = 0xC;
        return &D_00221CA8;
    case 0x11:
        *arg2 = 0xC;
        return &D_00221CB8;
    default:
        return 0;
    }
}
