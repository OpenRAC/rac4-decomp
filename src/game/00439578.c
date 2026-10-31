#include "common.h"

extern void func_001598F8(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5, s32 p6, s32 p7, s64 p8);

// Calls func_001598F8 with the constant 0xBFE87362, 8, the four arguments, two zeros, and the fifth argument last.
void func_00439578(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s64 arg4) {
    func_001598F8(0xBFE87362, 8, arg0, arg1, arg2, 0, 0, arg3, arg4);
}
