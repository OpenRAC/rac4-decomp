#include "common.h"

s32 D_002215D0 __attribute__((section(".sdata"))) = 0;
s32 D_002215C8 __attribute__((section(".sdata"))) = 0;

/* from rac3-decomp's func_L04_00313D88 */
s32 *func_L01_004C8A38(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 19:
        *a2 = 12;
        return &D_002215D0;
    case 20:
        *a2 = 8;
        return &D_002215C8;
    }
    return 0;
}
