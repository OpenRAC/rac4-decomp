#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
} Type2;

typedef struct {
    u8 pad0[0xAC];
    s32 fAC;
    Type2 *fB0[96];
    s32 f230;
} Type1;

// Finds the next slot after arg1 (or the current one) whose state is at least 4, wrapping around.
s32 func_L00_0071B7D0(Type1 *arg0, s32 arg1) {
    s32 r = -1;
    s32 i;
    s32 k;
    s32 idx;

    if (arg1 == -1) {
        arg1 = arg0->f230;
    }
    for (i = 0; i < arg0->fAC; i++) {
        k = i + 1;
        idx = (arg1 + k) % arg0->fAC;
        if (arg0->fB0[idx]->f4 >= 4) {
            r = idx;
            break;
        }
    }
    return r;
}
