#include "common.h"

/* Subtract the first table entry from arg0 that fits, scanning down from the table end. */
extern s16 D_003DB0A0[];

s32 func_004E2AF8(s32 arg0) {
    s32 a0 = arg0;
    s32 i;
    if (a0 >= 100) {
        i = 0x4F;
        do {
            s16 v = D_003DB0A0[i];
            if (a0 >= v && v != 0) {
                a0 -= v;
                break;
            }
            i--;
        } while (i >= 0);
    }
    return a0;
}
