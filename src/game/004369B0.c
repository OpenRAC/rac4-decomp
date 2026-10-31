#include "common.h"

extern int D_3284A0[];

/* Checks if one of four words at arg0's entry in D_3284A0 is zero. */
int func_004369B0(int arg0) {
    int *ptr;
    int i;

    ptr = (int *)&D_3284A0 + arg0 * 4;
    for (i = 0; i < 4; i++) {
        if (*ptr == 0) {
            return 0;
        }
        ptr++;
    }
    return 1;
}
