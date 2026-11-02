#include "common.h"

// Call func_L00_00770CD0 for arg1 and for arg1 + 0xC.

extern void func_L00_00770CD0(s32 arg0, u8 *arg1);

void func_L00_00770D40(s32 arg0, u8 *arg1) {
    func_L00_00770CD0(arg0, arg1);
    func_L00_00770CD0(arg0, arg1 + 0xC);
}
