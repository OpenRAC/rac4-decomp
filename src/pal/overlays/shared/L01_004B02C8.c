#include "common.h"

/* Address-only markers: retail reaches both through $gp. */
s32 D_002213EC = 0;
s32 D_002213FC = 0;

/* PAL: from rac3-decomp's func_L04_00313D88 */
void *func_L01_004B02C8(s32 arg0, s32 arg1, s32 *arg2) {
    switch (arg1) {
    case 17:
        *arg2 = 12;
        return &D_002213EC;
    case 18:
        *arg2 = 8;
        return &D_002213FC;
    default:
        return 0;
    }
}
