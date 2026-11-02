#include "common.h"

// Call func_L00_007790B8 for arg1 and for arg1 + 0xC.

extern void func_L00_007790B8(s32 arg0, u8 *arg1);

void func_L00_00779128(s32 arg0, u8 *arg1) {
    func_L00_007790B8(arg0, arg1);
    func_L00_007790B8(arg0, arg1 + 0xC);
}
