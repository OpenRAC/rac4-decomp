#include "common.h"

// Call func_L00_00771970 for arg1 and for arg1 + 0xC.

extern void func_L00_00771970(s32 arg0, u8 *arg1);

void func_L00_007719E0(s32 arg0, u8 *arg1) {
    func_L00_00771970(arg0, arg1);
    func_L00_00771970(arg0, arg1 + 0xC);
}
