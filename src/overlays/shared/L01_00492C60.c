#include "common.h"

s32 D_00221C30 __attribute__((section(".sdata"))) = 0;
s32 D_00221C40 __attribute__((section(".sdata"))) = 0;

/* from rac3-decomp's func_L01_003A4938 */
s32 *func_L01_00492C60(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 20:
        *a2 = 8;
        return &D_00221C40;
    case 19:
        *a2 = 12;
        return &D_00221C30;
    }
    return 0;
}
