#include "common.h"

extern s32 func_005015B0(s32, s32);
s32 D_00220B50 = 0;

/* 1 when D_00220B50 equals a1, else what func_005015B0(a0, a1) returns. */
s32 func_0050C530(s32 a0, s32 a1) {
    s32 r;
    if (D_00220B50 != a1) {
        r = func_005015B0(a0, a1);
    } else {
        r = 1;
    }
    return r;
}
