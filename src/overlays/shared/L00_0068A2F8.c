#include "common.h"

extern void func_0068A020(s32, s32, s32, s32, s32);

// Creates a 256x256 render target from the passed-in resource and size.
void func_L00_0068A2F8(s32 arg0, s32 arg1, s32 arg2) {
    func_0068A020(arg0, arg1, 0x100, 0x100, arg2);
}
