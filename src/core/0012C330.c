/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0012A718();
extern s32 D_0016473C[];
extern s32 D_1A9340[];
extern s32 D_1A9380[];
extern s32 D_1A93C0[];

// Stores arg0 in a global, calls func_0012A718 with two tables, and returns the result word or -1 on failure.
s32 func_0012C330(s32 arg0) {
    s32 r;

    if (D_0016473C[0] < 0) {
        return 0;
    }
    D_1A93C0[0] = arg0;
    r = func_0012A718(D_1A9340, 2, 0, D_1A93C0, 4, D_1A9380, 4, 0, 0);
    if (r < 0) {
        return -1;
    }
    return D_1A9380[0];
}
