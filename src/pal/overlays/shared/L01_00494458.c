#include "common.h"

/* Address-only markers: retail reaches both through $gp. */
s32 D_0022127C = 0;
s32 D_0022128C = 0;

/* PAL: from rac3-decomp's func_L01_003A4938 */
s32 *func_L01_00494458(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 20:
        *a2 = 8;
        return &D_0022128C;
    case 19:
        *a2 = 12;
        return &D_0022127C;
    }
    return 0;
}
