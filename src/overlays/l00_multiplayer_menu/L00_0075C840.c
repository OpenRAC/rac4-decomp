#include "common.h"

extern s32 D_172160[];
extern u8 *D_0021DFE8;

/* Counts slots up to arg1 whose team byte equals the current team and says whether slot arg1 does */
s32 func_L00_0075C840(s32 arg0, s32 arg1, s32 *arg2) {
    s32 i;

    *arg2 = -1;
    if (D_0021DFE8 != 0 && arg1 >= 0) {
        i = 0;
        do {
            if (*(u8 *)((u32)D_0021DFE8 + i + 0x104) == D_172160[4]) {
                *arg2 += 1;
            }
            i++;
        } while (i <= arg1);
    }
    return *(u8 *)((u32)D_0021DFE8 + arg1 + 0x104) == D_172160[4];
}
