#include "common.h"

extern s32 func_006EBF70();

// Calls func_006EBF70 with the caller's two arguments and 0, and returns whether the result is nonzero.
s32 func_L00_006EBFC0(void *arg0, s32 arg1) {
    return func_006EBF70(arg0, arg1, 0) != 0;
}
