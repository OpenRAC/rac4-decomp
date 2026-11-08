#include "common.h"

typedef void (*Fn_335C70)(u8 *);
extern u8 *func_00595DA0(void *);
extern void *D_00242358[];

/* from rac3-decomp's func_L01_00337EA8, constants adapted */
s32 func_L01_0045FEE8(void) {
    s32 r = 0;
    u8 *v = 0;
    if (D_00242358[0] != 0) {
        v = func_00595DA0(D_00242358[0]);
    }
    if (v != 0) {
        r = v[54] == 1;
    }
    return r;
}
