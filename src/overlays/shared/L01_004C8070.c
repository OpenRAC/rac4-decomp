#include "common.h"

/* Calls the three-parameter update routine with the global object at 0x0022B20
   and the argument's +0x10 / +0xF0 offsets, passing three zero arguments. */
extern s32 func_L01_00550790(s32 unused0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern s32 D_00222B20;

void func_L01_004C8070(s32 arg0) {
    func_L01_00550790((s32)&D_00222B20, arg0, arg0 + 0x10, arg0 + 0xF0, 0, 0, 0);
}
