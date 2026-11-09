#include "common.h"

extern s32 func_00498368(s32, s32);
extern s32 func_00505B20(void);
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
s32 D_0021F598 = 0;

/* Pick between mode-0 and mode-1 results of func_00498368, recording which in D_0021F598. */
s32 func_004983E8(s32 arg0) {
    s32 r;
    s32 r2;

    if (D_0021EDD4 != 1) {
        D_0021F598 = 0;
        r = func_00498368(0, arg0);
        if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
            r2 = func_00498368(1, arg0);
            if ((r2 != 0 && r2 < r) || r == 0) {
                D_0021F598 = 1;
                r = r2;
            }
        }
    } else {
        D_0021F598 = func_00505B20();
        r = func_00498368(func_00505B20(), arg0);
    }
    return r;
}
