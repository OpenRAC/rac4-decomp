#include "common.h"

extern s32 func_00611408();

// Calls func_00611408 with the caller's two arguments and 0, and returns whether the result is nonzero.
s32 func_L41_00611458(void *arg0, s32 arg1) {
    return func_00611408(arg0, arg1, 0) != 0;
}
