/* cflags: @ee29 -O2 -G0 */
#include "common.h"

/* Stores arg0 in D_1A93C0 and runs func_0012A718 on the D_1A9340 request; returns D_1A9380 on success, else 0. */
extern s32 D_0016473C[];
extern s32 D_1A9340[];
extern s32 D_1A9380[];
extern s32 D_1A93C0[];
extern s32 func_0012A718();

s32 func_0012C240(s32 arg0) {
    s32 r;

    if (D_0016473C[0] < 0) {
        return 0;
    }
    D_1A93C0[0] = arg0;
    r = func_0012A718(D_1A9340, 1, 0, D_1A93C0, 4, D_1A9380, 4, 0, 0);
    if (r >= 0) {
        return D_1A9380[0];
    }
    return 0;
}
