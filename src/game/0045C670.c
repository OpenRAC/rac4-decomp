#include "common.h"

extern s32 D_0021EDD4;
extern u8 D_0021EE18;
extern s32 D_221E28;
extern s32 D_23AB0C[];

/* Writes the table offset for arg0 to *arg1 (or the ED90 value when set); returns -1 if arg0 is above 0x40000. */
s32 D_0021ED90 = 0;

s32 func_0045C670(u32 arg0, s32 *arg1) {
    if (arg0 > 0x40000U) {
        *arg1 = 0;
        return -1;
    }
    if (D_0021EDD4 == 1 || D_0021EE18 != 0 || D_0021ED90 == 0) {
        *arg1 = (D_23AB0C[0] + D_221E28) - arg0;
    } else {
        *arg1 = D_0021ED90;
    }
    return 0;
}
