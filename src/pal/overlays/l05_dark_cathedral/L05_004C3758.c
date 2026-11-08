#include "common.h"

/* Address-only markers: retail reaches these through $gp ($gp = 0x2259FF = D_00220E7C + 0x4B83 (src/pal/game/00540FA8.c)). */
s32 D_00222010 = 0;
s32 D_00222018 = 0;

/* PAL: from rac3-decomp's func_L04_00313D88 */
s32 *func_L05_004C3758(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 11:
        *a2 = 16;
        return &D_00222018;
    case 20:
        *a2 = 8;
        return &D_00222010;
    }
    return 0;
}
