#include "common.h"

s32 D_00221D20 = 0;
s32 D_00221D28 = 0;

/* PAL: from rac3-decomp's func_L01_003A4938 */
s32 *func_L01_00495118(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 20:
        *a2 = 8;
        return &D_00221D20;
    case 19:
        *a2 = 12;
        return &D_00221D28;
    }
    return 0;
}
