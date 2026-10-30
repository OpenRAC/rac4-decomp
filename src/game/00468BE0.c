#include "common.h"

extern s32 func_00468B40(s32 *arg0);
extern s32 func_00468B78(s32 arg0, s32 arg1);
extern s32 D_003D80F0[];

// Returns func_00468B78(arg0, arg1) when func_00468B40 on D_003D80F0 is at least arg1, otherwise 0.
s32 func_00468BE0(s32 arg0, s32 arg1) {
    s32 result;

    if (func_00468B40(D_003D80F0) >= arg1) {
        result = func_00468B78(arg0, arg1);
    } else {
        result = 0;
    }
    return result;
}
