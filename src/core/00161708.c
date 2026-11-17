#include "common.h"

extern s32 func_001521D0(s32 a0, s32 a1, s32 a2, void *a3);
extern s32 func_00152348(s32 a0, s32 a1, s32 a2, void *a3);
extern s32 D_0021E05C;
s32 D_0021E020 = 0;
s32 D_0021E058 = 0;

/* Stores arg2 in slot arg0 of D_0021E058, calls one of two callees for arg0 == 0 or 1, and returns 1 unless the call result is negative. */
s32 func_00161708(s32 arg0, s32 arg1, s32 arg2) {
    s32 v;

    (&D_0021E058)[arg0] = arg2;
    if (arg0 == 0) {
        v = func_001521D0(D_0021E020, 0, arg1, &D_0021E058);
    } else if (arg0 == 1) {
        v = func_00152348(D_0021E020, 1, arg1, &D_0021E05C);
    } else {
        return 0;
    }
    if (v >= 0) {
        v = 1;
    } else {
        v = 0;
    }
    return v;
}
