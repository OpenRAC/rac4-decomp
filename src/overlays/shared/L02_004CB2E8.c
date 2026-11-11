#include "common.h"

extern void func_004C4D88(void *, void *);
extern void func_00638BF8(s32, s32, s32, s32, f32);
extern void func_005D7540(s32, s32, void *);
extern void func_00544188(void *, s32, s32);

void func_L02_004CB2E8(u8 *arg0) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);
    s32 target = *(s32 *)(*(u8 **)(vars + 0x170) + 0x2B8);

    func_004C4D88(arg0, vars);
    func_00638BF8(target, 0x24, 0, 0, 10.0f);
    *(f32 *)(vars + 0x1F8) = 1.0f;
    func_005D7540(2, 0, arg0);
    func_00544188(arg0, 4, -1);
}
