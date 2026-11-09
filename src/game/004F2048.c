#include "common.h"

#include "common.h"

extern s32 func_0011D5D8(const char *, ...);
extern s32 D_00220920[];

// Calls func_0011D5D8 with a fixed global pointer and arg1's second word, then returns 1.
s32 func_004F2048(s32 arg0, s32 *arg1) {
    func_0011D5D8((const char *)D_00220920, arg1[1]);
    return 1;
}
