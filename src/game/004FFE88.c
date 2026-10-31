#include "common.h"

extern void func_00500950(u8 *p);
extern void func_004FFBC8(u8 **a0);
extern void func_004FFDF8(u8 **a0);
extern void func_004FFB98(u8 **a0);
extern void func_004FFE28(u8 **a0);

// Calls func_00500950 on the 0x1CC sub-block, runs four passes over the same object, then stores -1 at word 0x1C4.
void func_004FFE88(u8 **arg0) {
    func_00500950(*arg0 + 0x1CC);
    func_004FFBC8(arg0);
    func_004FFDF8(arg0);
    func_004FFB98(arg0);
    func_004FFE28(arg0);
    *(s32 *)(*arg0 + 0x1C4) = -1;
}
