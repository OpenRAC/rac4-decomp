#include "common.h"

extern void func_L01_0059B970(u8 *, u8 *, u8 *, u8 *, s32, s32);

void func_L01_0059B948(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, s32 arg4) {
    func_L01_0059B970(arg0, arg1, arg2, arg3, *(s32 *)(arg1 + 0x12C) != 0, arg4);
}
