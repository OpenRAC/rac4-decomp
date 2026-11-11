#include "common.h"

s32 D_00221DA0 = 0;
s32 D_00221DB0 = 0;

/* from rac3-decomp's func_L04_00313D88 */
s32 *func_L01_004AE7D8(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 17:
        *a2 = 12;
        return &D_00221DA0;
    case 18:
        *a2 = 8;
        return &D_00221DB0;
    }
    return 0;
}
