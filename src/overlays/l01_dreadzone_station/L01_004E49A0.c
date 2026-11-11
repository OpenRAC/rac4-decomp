#include "common.h"

s32 D_002223D8 = 0;
s32 D_002223E8 = 0;

/* from rac3-decomp's func_L01_003A4938 */
s32 *func_L01_004E49A0(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 20:
        *a2 = 8;
        return &D_002223E8;
    case 19:
        *a2 = 12;
        return &D_002223D8;
    }
    return 0;
}
