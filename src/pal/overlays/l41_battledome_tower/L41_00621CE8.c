/* cflags: -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses */
/* C adapted from rac3-decomp func_L40_005416F0 (commit cd0e7c20fd8a). */
#include "common.h"


extern s32 D_00223854[];
extern s32 D_00223850;

s32 func_L41_00621CE8(s32 *a) {
    s32 r = 0;
    s32 v = D_00223854[0];
    if (v != -1) {
        s32 x = a[1];
        if (x == v || (x == -1 && D_00223850 == v)) {
            r = 1;
        }
    }
    return r;
}
