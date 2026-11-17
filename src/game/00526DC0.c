#include "common.h"

typedef struct {
    u8 pad0[0xE0];
    s32 fE0[0x40];
} Type1;
extern u8 D_00171D3D[];
extern s32 D_0021EE54;
extern Type1 D_1DFD70[];
extern s32 D_21DA48;

/* Test one bit of a per-slot flag table when the object and globals allow it, else 1. */
s32 func_00526DC0(u8 *arg0, s32 arg1) {
    s32 q;
    s32 r;
    s32 idx;

    if (arg0[0x266D] != 0) {
        if (D_00171D3D[0] == 0) {
            return 1;
        }
        if (D_0021EE54 == 0) {
            q = arg1 / 32;
            r = arg1 - (q << 5);
            idx = (*(s32 (**)(u8 *))(*(u8 **)(arg0 + 0x14) + 0x4C))(arg0);
            return D_1DFD70[(&D_21DA48)[idx]].fE0[q] & (1 << r);
        }
    }
    return 1;
}
