#include "common.h"

s32 D_002221D0 = 0;
s32 D_002221D8 = 0;

/* from rac3-decomp's func_L01_003A4938 */
s32 *func_L01_0048FF30(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 20:
        *a2 = 8;
        return &D_002221D0;
    case 19:
        *a2 = 12;
        return &D_002221D8;
    }
    return 0;
}
