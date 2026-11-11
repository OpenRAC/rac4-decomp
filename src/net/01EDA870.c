/* cflags: @ee296 -O2 -G0 -fno-gcse */
#include "common.h"
extern s32 D_0016A048[];
extern s32 D_0016A074[];
extern s32 (*D_00199180)(s32, void *, s32);

s32 func_01EDA870(void) {
    s32 r = D_0016A074[0];
    if (r == 0) {
        r = D_00199180(0, D_0016A048, 0x2C);
        D_0016A074[0] = r;
    }
    return r;
}
