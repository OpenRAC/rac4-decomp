#include "common.h"

// Call func_L00_004F84C8(0x10, 0x6D, 0xE, 0, 0) and return 0.

extern void func_L00_004F84C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

s32 func_L00_00505FF8(void) {
    func_L00_004F84C8(0x10, 0x6D, 0xE, 0, 0);
    return 0;
}
