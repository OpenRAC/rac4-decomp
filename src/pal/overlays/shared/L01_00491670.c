#include "common.h"

s32 D_002213F4 = 0;
s32 D_002213FC = 0;

/* PAL: from rac3-decomp's func_L01_003A4938 */
s32 *func_L01_00491670(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 20:
        *a2 = 8;
        return &D_002213F4;
    case 19:
        *a2 = 12;
        return &D_002213FC;
    default:
        return 0;
    }
}
