#include "common.h"

extern s32 func_L00_00710750();
extern s32 func_L00_007168B0(void *, s32);
extern s32 D_004B9678[];

void *func_L00_00716828(u8 *arg0, s32 arg1) {
    func_L00_00710750(arg0);
    arg0[0x160] = 0;
    *(s32 *)(arg0 + 0x22C) = 0;
    *(s32 *)(arg0 + 0x230) = 0;
    *(s32 *)(arg0 + 0x234) = 0;
    *(s32 **)(arg0 + 0x58) = D_004B9678;
    func_L00_007168B0(arg0, arg1);
    return arg0;
}
