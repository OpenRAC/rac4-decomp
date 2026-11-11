#include "common.h"

s32 D_002216D8 = 0;
s32 D_002216E8 = 0;

/* from rac3-decomp's func_L04_003CD280 */
s32 *func_L01_00453980(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 0:
        *a2 = 12;
        return &D_002216D8;
    case 20:
        *a2 = 8;
        return &D_002216E8;
    }
    return 0;
}
