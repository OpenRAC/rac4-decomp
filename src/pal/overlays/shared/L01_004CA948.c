#include "common.h"

s32 D_00222080 = 0;
s32 D_00222078 = 0;

/* PAL: from rac3-decomp's func_L04_00313D88 */
s32 *func_L01_004CA948(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 19:
        *a2 = 12;
        return &D_00222080;
    case 20:
        *a2 = 8;
        return &D_00222078;
    }
    return 0;
}
