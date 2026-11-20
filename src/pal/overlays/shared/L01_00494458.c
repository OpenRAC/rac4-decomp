#include "common.h"

/* Address-only markers: retail reaches both through $gp. */
s32 D_00221CE0 = 0;
s32 D_00221CF0 = 0;

/* PAL: from rac3-decomp's func_L01_003A4938 */
s32 *func_L01_00494458(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 20:
        *a2 = 8;
        return &D_00221CF0;
    case 19:
        *a2 = 12;
        return &D_00221CE0;
    }
    return 0;
}
