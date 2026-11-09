#include "common.h"

extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00504238(s32, f32, f32);
extern s32 D_00221748;

void func_004B4A98(void) {
    func_00504238(func_004A1A60(&D_00221748, 1), 0.5f, 0.7f);
    func_00504238(func_004A1A60(&D_00221748, 7), -0.5f, 0.15f);
    func_00504238(func_004A1A60(&D_00221748, 0xF), 1.35f, 0.5f);
    func_00504238(func_004A1A60(&D_00221748, 0x2E), -0.25f, 0.5f);
    func_00504238(func_004A1A60(&D_00221748, 0x36), 1.25f, 0.5f);
}
