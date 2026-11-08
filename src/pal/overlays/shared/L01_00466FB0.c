#include "common.h"

/* Address-only markers: retail reaches these through $gp ($gp = 0x2259FF in PAL level_01). */
s32 D_00221930 = 0;
s32 D_00221938 = 0;
s32 D_00221940 = 0;

/* PAL: from rac3-decomp's func_L01_003A0710 */
s32 *func_L01_00466FB0(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 21:
        *a2 = 4;
        return &D_00221930;
    case 20:
        *a2 = 8;
        return &D_00221938;
    case 19:
        *a2 = 12;
        return &D_00221940;
    }
    return 0;
}
