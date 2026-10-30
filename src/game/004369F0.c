#include "common.h"

extern s32 D_3284A0[];

/* Clears the first of four words at arg1's entry in D_3284A0 that equals arg0. */
s32 func_004369F0(s32 arg0, s32 arg1) {
    s32 *ptr;
    s32 i;

    ptr = &D_3284A0[arg1 * 4];
    i = 0;
    do {
        i++;
        if (*ptr != arg0) {
            ptr++;
        } else {
            *ptr = 0;
            return 1;
        }
    } while (i < 4);
    return 0;
}
