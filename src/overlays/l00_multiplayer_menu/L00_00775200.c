#include "common.h"

extern u8 D_004C1610[];
extern void func_0011D920(u8 *, u8 *, s32, s32, s32);

void func_L00_00775200(s32 *arg0, u8 *arg1) {
    func_0011D920(arg1, D_004C1610, arg0[1], arg0[2], arg0[3]);
}
