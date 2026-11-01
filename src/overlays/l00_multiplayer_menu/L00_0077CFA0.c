#include "common.h"

// Call func_L00_0077CF30 for arg1 and for arg1 + 0xC.

extern void func_L00_0077CF30(s32 arg0, u8 *arg1);

void func_L00_0077CFA0(s32 arg0, u8 *arg1) {
    func_L00_0077CF30(arg0, arg1);
    func_L00_0077CF30(arg0, arg1 + 0xC);
}
