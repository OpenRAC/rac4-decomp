#include "common.h"

s32 D_00221788 = 0;
s32 D_00221798 = 0;

/* PAL: from rac3-decomp's func_L04_003CD280 */
s32 *func_L01_00454C58(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 0:
        *a2 = 12;
        return &D_00221788;
    case 20:
        *a2 = 8;
        return &D_00221798;
    }
    return 0;
}
